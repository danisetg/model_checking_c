#include "Lexer.h"
#include "Token.h"
#include "Helper.h"
#include <regex>
int tokensLength = 40;

//predefined list of tokens to to find program code
Token tokens[40] = {
            Token("OPEN_BRACE", regex("\\{"), ""),
            Token("CLOSE_BRACE", regex("\\}"), ""),
            Token("OPEN_PARENTHESIS", regex("\\("), ""),
            Token("OPEN_BRACKET", regex("\\["), ""),
            Token("CLOSE_PARENTHESIS", regex("\\)"), ""),
            Token("CLOSE_BRACKET", regex("\\]"), ""),
            Token("SEMICOLON", regex(";"), ""),
            Token("NEGATION", regex("-"), ""),
            Token("ADDITION", regex("\\+"), ""),
            Token("MULTIPLICATION", regex("\\*"), ""),
            Token("MOD", regex("%"), ""),
            Token("DIVISION", regex("/"), ""),
            Token("BITWISE_COMPLEMENT", regex("~"), ""),
            Token("LOGICAL_AND", regex("&&"), ""),
            Token("LOGICAL_OR", regex("\\|\\|"), ""),
            Token("BITWISE_AND", regex("&"), ""),
            Token("BITWISE_OR", regex("\\|"), ""),
            Token("EQUAL_TO", regex("=="), ""),
            Token("NOT_EQUAL_TO", regex("!="), ""),
            Token("LESS_OR_EQUAL_TO", regex("<="), ""),
            Token("LESS_THAN", regex("<"), ""),
            Token("GREATER_OR_EQUAL_TO", regex(">="), ""),
            Token("GREATER_THAN", regex(">"), ""),
            Token("ASSIGNMENT", regex("="), ""),
            Token("LOGICAL_NEGATION", regex("!"), ""),
            Token("INT_KEYWORD", regex("int"), ""),
            Token("STRUCT_KEYWORD", regex("struct"), ""),
            Token("RETURN_KEYWORD", regex("return"), ""),
            Token("IF_KEYWORD", regex("if"), ""),
            Token("FOR_KEYWORD", regex("for"), ""),
            Token("WHILE_KEYWORD", regex("while"), ""),
            Token("DO_KEYWORD", regex("do"), ""),
            Token("BREAK_KEYWORD", regex("break"), ""),
            Token("CONTINUE_KEYWORD", regex("continue"), ""),
            Token("ELSE_KEYWORD", regex("else"), ""),
            Token("COLON", regex(":"), ""),
            Token("COMMA", regex(","), ""),
            Token("QUESTION_MARK", regex("\\?"), ""),
            Token("IDENTIFIER", regex("[a-zA-Z]\\w*"), ""),
            Token("INTEGER", regex("[0-9]+"), "")
            };


//predefined program special characters that can be found joint to words
string predefinedTwoCharacters[4] = {"==", "!=", "++", "--"};
string predefinedCharacters = "{}();-~!+*/%?:,[]";

bool isPredefinedWord(string match) {
    for (int i = 0; i < 4; i++) {
        if (predefinedTwoCharacters[i] == match)
            return true;
    }
    return false;
}
//function for getting a vector with all words and special characters found in program code
vector<string> getProgramWords(string program) {
    int len = program.length();
    string word = "";
    vector<string> str_arr;
    for(int i = 0; i < len; i++) {
        bool _isPredefinedWord = false;
        if (i < len - 1) {
            _isPredefinedWord = isPredefinedWord(program.substr(i,2));
        }
        int tmp = predefinedCharacters.find(program[i]);
        //if any space or special character has not being found, we are still reading the word
        if(program[i] != ' ' && program[i] != '\n' && tmp == string::npos && !_isPredefinedWord) {
            word += program[i];
        //else, we finished reading the word, so we add it to the vector
        } else {
            if(word.length()) {
                str_arr.push_back(word);
                word = "";
            }

            //if we read a special character, we add it too, as a word
            if(_isPredefinedWord) {
                str_arr.push_back(program.substr(i,2));
                i++;
            }else if(tmp != string::npos) {
                str_arr.push_back(string(1, program[i]));
            }

        }
    }
    if(word.length())
        str_arr.push_back(word);
    return str_arr;
}

//function for extracting program tokens and storing them in a vector the order they are found
vector<Token> getTokens(string program) {
    vector<string> words = getProgramWords(program);
    vector<Token> foundTokens;
    int len = words.size();
    //iterate the words vector and for each word check if it matches any of the predefined tokens
    for(int i = 0; i < len; i++) {
        cout<<words[i]<<endl;
        for(int h = 0; h < tokensLength; h++) {
            //if word matches with a predefined token, add the token to the vector
            if(regex_match(words[i], tokens[h].regExp)) {
                Token token = tokens[h];
                token.word = words[i];
                foundTokens.push_back(token);
                break;
            }

        }
    }

    return foundTokens;
}




