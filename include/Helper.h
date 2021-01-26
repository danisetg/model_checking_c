#ifndef HELPER_H
#define HELPER_H
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <Token.h>
#include <sstream>
#include <fstream>
#include <optional>
using std::queue;
using std::ofstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::optional;

vector<string> split(string str, char delimiter);

string fileToString(string dir);

void mad(string message);

string printTabs(int tabs);

#endif // HELPER_H
