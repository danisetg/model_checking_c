#include "Array.h"

Array::Array()
{
    //ctor
}

Array::Array(const Array &arr) {
    positions = arr.positions;
    name = arr.name;
}

void Array::parse(string _name, deque<Token>& tokens, vector<string>& _funCalls) {
    if(tokens.empty())
        mad("Array is empty");

    name = _name;

    Token token = tokens.front();

    while(token.type == "OPEN_BRACKET") {
        tokens.pop_front();
        Expression exp;
        exp.parse(tokens, _funCalls);
        positions.push_back(exp);
        token = tokens.front();
        if(token.type != "CLOSE_BRACKET")
            mad("Missing ']'");
        tokens.pop_front();
        token = tokens.front();
    }
}

string Array::translate(string fun_name, int& tabs, int& funCallNumber, string& previousCode) {
    string code = name + "[";
    vector<int> arrayDimensions = getArrayDimensions(name);
    if(!arrayDimensions.size())
        arrayDimensions = getLocalArrayDimensions(name, fun_name);
    if(arrayDimensions.size()) {
        code += getPosition(fun_name, tabs, funCallNumber, previousCode, arrayDimensions, arrayDimensions.size() - 1) + "]";
    } else
        mad("Array " + name + " was never declared");
    return code;
}

string Array::getPosition(string fun_name, int& tabs, int& funCallNumber, string& previousCode,
                          vector<int> dimensions, int dimsLength) {
    if(dimsLength == 0)
        return "(" + positions[0].translate(fun_name, tabs, funCallNumber, previousCode) + ")";
    return "(" + getPosition(fun_name, tabs, funCallNumber, previousCode, dimensions, dimsLength - 1)
            + "*" + to_string(dimensions[dimsLength]) + " + " + positions[dimsLength].translate(fun_name, tabs, funCallNumber, previousCode) + ")";
}

void Array::changeVariablesName(string prefix) {
    name = prefix + "_" + name;
    for(int i = 0; i < positions.size(); i++) {
        positions[i].changeVariablesName(prefix);
    }
}
