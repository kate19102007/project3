#pragma once
#include <vector>
#include <cmath>

void generateVector(std::vector<double>& V, int size);
void sortASC(std::vector<double>& V);
std::vector<double> calculateGroupSumsASC(const std::vector<double>& sorted, int n);
std::vector<double> calculateGroupSumsDESC(const std::vector<double>& sorted, int n);
double calculateDiff(const std::vector<double>& sums);
void findRepeats(const std::vector<double>& V, std::vector<double>& values, std::vector<int>& counts);