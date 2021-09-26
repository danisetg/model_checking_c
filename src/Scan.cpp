#include "Scan.h"

Scan::Scan()
{
    //ctor
}

Scan::Scan(const Scan &scan) {
    for(int i = 0; i < scan.variables.size(); i++) {
        string aux = scan.variables[i];
        variables.push_back(scan.variables[i]);
    }
}

void Scan::parse(deque<Token>& tokens) {
    if(tokens.empty())
        mad("Missing variable");

    Token token = tokens.front();

    if(token.type != "SCANF_KEYWORD")
        mad("Not a scanf function");

    tokens.pop_front();

    token = tokens.front();

    if(token.type != "OPEN_PARENTHESIS")
        mad("Missing (");

    tokens.pop_front();

    token = tokens.front();
    while(token.type != "COMMA") {
        tokens.pop_front();
        token = tokens.front();
    }

    while(token.type == "COMMA") {
        tokens.pop_front();
        token = tokens.front();
        if(token.type != "BITWISE_AND")
            mad("Missing reference &");
        tokens.pop_front();
        token = tokens.front();
        variables.push_back(token.word);
        cout<<"Proporcione los límites para la variable "<<token.word<<endl;
        int minim, maxim;
        scanf("%d %d", &minim, &maxim);
        limits.push_back(make_pair(minim, maxim));
        tokens.pop_front();
        token = tokens.front();
    }
    if(token.type != "CLOSE_PARENTHESIS")
        mad("Missing ')'");
    tokens.pop_front();
}

string Scan::translate(int& tabs) {
    string code = "";
    for(int i = 0; i < variables.size(); i++) {
        int minim = limits[i].first;
        int maxim = limits[i].second;
        code += printTabs(tabs) + "run input(ret_input, " + to_string(minim) + ", " + to_string(maxim) + ");\n";
        code += printTabs(tabs) + "ret_input ? " + variables[i] + ";\n";
    }
    return code;
}

void Scan::changeVariablesName(string prefix) {
    for(int i = 0; i < variables.size(); i++) {
        variables[i] = prefix + "_" + variables[i];
    }
}
