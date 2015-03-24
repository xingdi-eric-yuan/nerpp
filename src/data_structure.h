#pragma once
#include "general_settings.h"

using namespace std;

///////////////////////////////////
// mitie Structures
///////////////////////////////////
struct singleWord {
    std::string word;
    std::string label;
    std::string pred;
    singleWord(string a, string b) : word(a), label(b), pred(""){}
    singleWord(string a, string b, string c) : word(a), label(b), pred(c){}
};
