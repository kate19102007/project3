#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <algorithm>
#include "func.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int size;
    cout << "Input vector size: ";
    cin >> size;

    vector<double> V;
    generateVector(V, size);

    cout << "\nOriginal vector:\n";
    for (double x : V) cout << x << " ";

    vector<double> sorted = V;
    sortASC(sorted);

    cout << "\n\nSorted ASC:\n";
    for (double x : sorted) cout << x << " ";

    cout << "\n\nSorted DESC:\n";
    for (int i = static_cast<int>(sorted.size()) - 1; i >= 0; i--) cout << sorted[i] << " ";

    int n;
    cout << "\n\nInput group size n: ";
    cin >> n;

    vector<double> sumsASC = calculateGroupSumsASC(sorted, n);
    vector<double> sumsDESC = calculateGroupSumsDESC(sorted, n);

    cout << "\nGroup sums ASC:\n";
    for (double x : sumsASC) cout << x << " ";

    cout << "\nGroup sums DESC:\n";
    for (double x : sumsDESC) cout << x << " ";

    double diff = calculateDiff(sumsASC);
    cout << "\n\n|Smax - Smin| = " << diff << endl;

    vector<double> values;
    vector<int> counts;
    findRepeats(V, values, counts);

    cout << "\nRepeats:\n";
    for (size_t i = 0; i < values.size(); i++)
        cout << values[i] << " -> " << counts[i] << endl;

    json j;
    for (size_t i = 0; i < values.size(); i++)
        j["repeats"][to_string(values[i])] = counts[i];

    j["group_sums_ASC"] = sumsASC;
    j["group_sums_DESC"] = sumsDESC;
    j["difference"] = diff;

    ofstream file("result.json");
    file << j.dump(4);
    file.close();

    cout << "\nResults saved to result.json\n";

    return 0;
}