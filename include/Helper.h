#ifndef HELPER_H
#define HELPER_H
#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <Token.h>
#include <sstream>
#include <direct.h>
#include <io.h>
#include <fstream>
#include <optional>
#include <set>
#include <iterator>
#include <map>
#include "ArrayDecl.h"
#include "PointerDecl.h"
#include "StructType.h"
using std::deque;
using std::map;
using std::ofstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::optional;
using std::set;
using std::iterator;
using std::to_string;
using std::stoi;
using std::ifstream;
using std::ostringstream;



extern vector<ArrayDecl> globalArrays;
extern vector<PointerDecl> pointers;
extern set<string> pointersTypes;
extern vector<StructType> structTypes;

vector<string> split(string str, char delimiter);

string fileToString(string dir);

void mad(string message);

string printTabs(int tabs);

void saveArray(string name, vector<int> dimensions);

void savePointer(string name, string type);

void saveStructType(string name, vector<pair<string, string> > members);

vector<string> getPointerTypes();

vector<pair<string, string> > getStructMembers(string name);

string getStructType(string name);

string getPointerType(string pointerName);

vector<int> getArrayDimensions(string name);

void saveLocalArray(string name, vector<int> dimensions, string functionName);

vector<int> getLocalArrayDimensions(string name, string functionName);

string exec(const char* cmd);

void createFolderIfNotExists(const char* address);

#endif // HELPER_H
