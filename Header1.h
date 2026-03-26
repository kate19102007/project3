#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void generateVector(vector<int>& V, int size);
void printVector(const vector<int>& V, const string& label);
void sortASC(vector<int>& asc);
void sortDESC(vector<int>& desc);
vector<int> calculateGroupSums(const vector<int>& data, int n);
void findRepeats(const vector<int>& V, vector<int>& values, vector<int>& counts);
void saveToJSON(const vector<int>& values, const vector<int>& counts, const vector<int>& sumsASC, const vector<int>& sumsDESC, int diff);