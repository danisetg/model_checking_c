#include "Helper.h"

vector<ArrayDecl> globalArrays;
vector<ArrayDecl> localArrays;
vector<PointerDecl> pointers;
set<string> pointersTypes;
vector<StructType> structTypes;

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
string replaceAll(string s, string a, string b) {
    string aux = s;
    while (true) {
     /* Locate the substring to replace. */
     int index = aux.find(a);
     cout<<aux<<" "<<a<<" "<<b<<" "<<(index == std::string::npos)<<endl;
     if (index == std::string::npos) break;

     /* Make the replacement. */
     aux = aux.replace(index, a.length(), b);

    }
    return aux;
}
//reads a file and saves its content in a string
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

void savePointer(string name, string type) {
    PointerDecl ptr;
    ptr.name = name;
    ptr.type = type;
    pointers.push_back(ptr);
    pointersTypes.insert(type);
}

void saveStructType(string name, vector<pair<string, string> > members) {
    StructType structType;
    structType.name = name;
    structType.members = members;
    structTypes.push_back(structType);
}

vector<string> getPointerTypes() {
    set<string>::iterator it;
    vector<string> types;
    for(it = pointersTypes.begin(); it != pointersTypes.end(); it++) {
        types.push_back(*it);
    }
    return types;
}

vector<pair<string, string> > getStructMembers(string name) {
    vector<pair<string, string> > members;
    for(int i = 0; i < structTypes.size(); i++) {
        if(name == structTypes[i].name)
            return structTypes[i].members;
    }
    return members;
}

string getPointerType(string pointerName) {
    for(int i = 0; i < pointers.size(); i++) {
        if(pointers[i].name == pointerName)
            return pointers[i].type;
    }
    return "-1";
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

string exec(const char* cmd) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) mad("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}


void createFolderIfNotExists(string address)
{
	//Judge whether the folder exists, create it if it does not exist
	string dir = address;

	if (_access(dir.c_str(), 0) == -1)
	{
		_mkdir(dir.c_str());
	}


}
