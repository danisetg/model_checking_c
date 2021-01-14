#ifndef HELPER_H
#define HELPER_H
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> split(string str, char delimiter);

string fileToString(string dir);

void mad(string message);

string printTabs(int tabs);

#endif // HELPER_H
