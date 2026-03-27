#include "func.h"
#include <cstdlib>
#include <algorithm>

void generateVector(std::vector<double>& V, int size) {
    for (int i = 0; i < size; i++)
        V.push_back((rand() % 1000) / 10.0);
}

void sortASC(std::vector<double>& V) {
    for (size_t i = 0; i < V.size(); i++)
        for (size_t j = 0; j < V.size() - 1; j++)
            if (V[j] > V[j + 1])
                std::swap(V[j], V[j + 1]);
}

std::vector<double> calculateGroupSumsASC(const std::vector<double>& sorted, int n) {
    std::vector<double> sums;
    for (size_t i = 0; i < sorted.size(); i += n) {
        double sum = 0;
        for (size_t j = i; j < i + n && j < sorted.size(); j++)
            sum += sorted[j];
        sums.push_back(sum);
    }
    return sums;
}

std::vector<double> calculateGroupSumsDESC(const std::vector<double>& sorted, int n) {
    std::vector<double> sums;
    for (int i = static_cast<int>(sorted.size()) - 1; i >= 0; i -= n) {
        double sum = 0;
        for (int j = i; j > i - n && j >= 0; j--)
            sum += sorted[j];
        sums.push_back(sum);
    }
    std::reverse(sums.begin(), sums.end()); // щоб порядок був від більшого до меншого
    return sums;
}

double calculateDiff(const std::vector<double>& sums) {
    double Smax = sums[0];
    double Smin = sums[0];
    for (size_t i = 1; i < sums.size(); i++) {
        if (sums[i] > Smax) Smax = sums[i];
        if (sums[i] < Smin) Smin = sums[i];
    }
    return std::abs(Smax - Smin);
}

void findRepeats(const std::vector<double>& V, std::vector<double>& values, std::vector<int>& counts) {
    for (double v : V) {
        bool found = false;
        for (size_t j = 0; j < values.size(); j++) {
            if (std::abs(values[j] - v) < 0.0001) {
                counts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            values.push_back(v);
            counts.push_back(1);
        }
    }
}