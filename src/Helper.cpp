#include <string>
#include "Helper.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>
#include <memory>
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;
using std::vector;

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


