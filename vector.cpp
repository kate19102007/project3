#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "json.hpp"
#include "Header.h"

using namespace std;
using json = nlohmann::json;

int main() {

    srand(time(0));

    int size;
    cout << "Input vector size: ";
    cin >> size;

    vector<int> V;
    for (int i = 0; i < size; i++)
        V.push_back(rand() % 100);

    cout << "\nOriginal vector:\n";
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";

    vector<int> asc = sortASC(V);
    cout << "\n\nSorted ASC:\n";
    for (int i = 0; i < asc.size(); i++)
        cout << asc[i] << " ";

    vector<int> desc = sortDESC(V);
    cout << "\n\nSorted DESC:\n";
    for (int i = 0; i < desc.size(); i++)
        cout << desc[i] << " ";

    int n;
    cout << "\n\nInput group size n: ";
    cin >> n;

    vector<int> sumsASC = groupSums(asc, n);
    cout << "\nGroup sums ASC:\n";
    for (int i = 0; i < sumsASC.size(); i++)
        cout << sumsASC[i] << " ";

    vector<int> sumsDESC = groupSums(desc, n);
    cout << "\nGroup sums DESC:\n";
    for (int i = 0; i < sumsDESC.size(); i++)
        cout << sumsDESC[i] << " ";

    int diff = diffMaxMin(sumsASC);
    cout << "\n\n|Smax - Smin| = " << diff << endl;

    vector<int> values;
    vector<int> counts;
    for (int i = 0; i < V.size(); i++) {
        bool found = false;
        for (int j = 0; j < values.size(); j++) {
            if (values[j] == V[i]) {
                counts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            values.push_back(V[i]);
            counts.push_back(1);
        }
    }

    cout << "\nRepeats:\n";
    for (int i = 0; i < values.size(); i++)
        cout << values[i] << " -> " << counts[i] << endl;

    json j;
    for (int i = 0; i < values.size(); i++)
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
