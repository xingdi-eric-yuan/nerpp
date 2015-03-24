#pragma once
#include <fstream>
#include <sstream>
#include "general_settings.h"

using namespace std;

void readPredData(std::string, std::vector<std::vector<singleWord> >&);
void readData(std::string, std::vector<std::vector<singleWord> >&);

void readLine(std::vector<string> &);

void splitData(string, double, string, string);

void showAccuracy(std::vector<std::vector<singleWord> >&);

void writeData(std::vector<std::string>&);