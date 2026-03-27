#pragma once
#include <vector>
#include <cmath>
#include"Header.h"
using namespace std;

vector<int> sortASC(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v.size() - 1; j++)
            if (v[j] > v[j + 1]) {
                int t = v[j]; v[j] = v[j + 1]; v[j + 1] = t;
            }
    return v;
}

vector<int> sortDESC(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v.size() - 1; j++)
            if (v[j] < v[j + 1]) {
                int t = v[j]; v[j] = v[j + 1]; v[j + 1] = t;
            }
    return v;
}

vector<int> groupSums(vector<int> v, int n) {
    vector<int> sums;
    for (int i = 0; i < v.size(); i += n) {
        int sum = 0;
        for (int j = i; j < i + n && j < v.size(); j++)
            sum += v[j];
        sums.push_back(sum);
    }
    return sums;
}

int diffMaxMin(vector<int> sums) {
    int mx = sums[0], mn = sums[0];
    for (int i = 1; i < sums.size(); i++) {
        if (sums[i] > mx) mx = sums[i];
        if (sums[i] < mn) mn = sums[i];
    }
    return abs(mx - mn);
}
