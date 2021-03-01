#include "Helper.h"

vector<ArrayDecl> globalArrays;
vector<ArrayDecl> localArrays;

vector<string> split(string str, char delimiter) {
    int len = str.length();
    string word = "";
    int cont = 0;
    vector<string> str_arr;
    for(int i = 0; i < len; i++) {
        if(str[i] != delimiter && str[i] != '\n') {
            word += str[i];
        } else {
            if(word.length()) {
                str_arr.push_back(word);
                word = "";
            }

        }
    }
    if(word.length())
        str_arr.push_back(word);
    return str_arr;
}

string fileToString(string dir) {
   ifstream f(dir); //taking file as inputstream
   string str;
   if(f) {
      ostringstream ss;
      ss << f.rdbuf(); // reading data
      str = ss.str();
   } else {
        cout<<"File not found"<<endl;
   }
   return str;
}

void inner_mad()
{
    throw std::exception();
}

void mad(string message)
{
    cout<<message<<endl;
    auto ptr = std::make_unique<int>();
    inner_mad();
}

string printTabs(int tabs) {
    string s = "";
    for(int i = 0; i < tabs; i++)
        s+='\t';
    return s;
}

void saveArray(string name, vector<int> dimensions) {
    ArrayDecl arr;
    arr.dimensions = dimensions;
    arr.name = name;
    globalArrays.push_back(arr);
}

vector<int> getArrayDimensions(string name) {
    vector<int> noResult;
    for(int i = 0; i < globalArrays.size(); i++) {
        if(globalArrays[i].name == name)
            return globalArrays[i].dimensions;
    }
    return noResult;
}

void saveLocalArray(string name, vector<int> dimensions, string functionName) {
    ArrayDecl arr;
    arr.dimensions = dimensions;
    arr.functionName = functionName;
    arr.name = name;
    globalArrays.push_back(arr);
}

vector<int> getLocalArrayDimensions(string name, string functionName) {
    vector<int> noResult;
    for(int i = 0; i < localArrays.size(); i++) {
        if(localArrays[i].name == name && localArrays[i].functionName == functionName)
            return localArrays[i].dimensions;
    }
    return noResult;
}

