#include "Lexer.h"
#include "Token.h"
#include "Helper.h"
#include <regex>
#include <iostream>
int tokensLength = 9;

//predefined list of tokens to to find program code
Token tokens[9] = {
            Token("OPEN_BRACE", regex("\\{"), ""),
            Token("CLOSE_BRACE", regex("\\}"), ""),
            Token("OPEN_PARENTHESIS", regex("\\("), ""),
            Token("CLOSE_PARENTHESIS", regex("\\)"), ""),
            Token("SEMICOLON", regex(";"), ""),
            Token("INT_KEYWORD", regex("int"), ""),
            Token("RETURN_KEYWORD", regex("return"), ""),
            Token("IDENTIFIER", regex("[a-zA-Z]\\w*"), ""),
            Token("INTEGER", regex("[0-9]+"), "")
            };

//predefined program special characters that can be found joint to words
string predefinedCharacters = "{}();";

//function for getting a vector with all words and special characters found in program code
vector<string> getProgramWords(string program) {
    int len = program.length();
    string word = "";
    vector<string> str_arr;
    for(int i = 0; i < len; i++) {
        int tmp = predefinedCharacters.find(program[i]);
        //if any space or special character has not being found, we are still reading the word
        if(program[i] != ' ' && program[i] != '\n' && tmp == string::npos) {
            word += program[i];
        //else, we finished reading the word, so we add it to the vector
        } else {
            if(word.length()) {
                str_arr.push_back(word);
                word = "";
            }
            //if we read a special character, we add it too, as a word
            if(tmp != string::npos) {
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




