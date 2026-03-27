#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

inline void sortAsc(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

inline void sortDesc(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

inline int sumOfElements(vector<int>& v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

inline void rmDuplicates(vector<int>& v, vector<int>& unique)
{
    for (int i = 0; i < v.size(); i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < unique.size(); j++)
        {
            if (v[i] == unique[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            unique.push_back(v[i]);
        }
    }
}

inline void printDifference(vector<int>& v1, vector<int>& v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < v1.size(); j++)
        {
            if (v1[i] == v1[j])
                count++;
        }

        if (count > 1)
            cout << v1[i] << " ";
    }
    cout << endl;
}

inline void JsonOut(ofstream& jout, int sum2, int sum3, int duplicatesCount, vector<int>& v1, vector<int>& v2)
{
    jout << "{\n";
    jout << "  \"S2\": " << sum2 << ",\n";
    jout << "  \"S3\": " << sum3 << ",\n";
    jout << "  \"S3 - S2\": " << sum3 - sum2 << ",\n";
    jout << "  \"duplicatesCount\": " << duplicatesCount << ",\n";
    jout << "  \"V1\": [";
    for (int i = 0; i < v1.size(); i++)
    {
        jout << v1[i];
        if (i < v1.size() - 1) {
            jout << ", ";
        }
    }
    jout << "],\n";
    jout << "  \"V2\": [";
    for (int i = 0; i < v2.size(); i++)
    {
        jout << v2[i];
        if (i < v2.size() - 1) {
            jout << ", ";
        }
    }
    jout << "]\n";
    jout << "}\n";
}