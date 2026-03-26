#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main() {

    srand(time(0));

    int size;
    cout << "Input vector size: ";
    cin >> size;

    vector<double> V;

    // генерація дробових чисел
    for (int i = 0; i < size; i++)
        V.push_back((rand() % 1000) / 10.0); // наприклад: 12.3

    cout << "\nOriginal vector:\n";
    for (double x : V)
        cout << x << " ";

    // -------------------
    // сортування (ОДИН раз ASC)
    // -------------------

    vector<double> sorted = V;

    for (int i = 0; i < sorted.size(); i++)
        for (int j = 0; j < sorted.size() - 1; j++)
            if (sorted[j] > sorted[j + 1]) {
                double t = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = t;
            }

    cout << "\n\nSorted ASC:\n";
    for (double x : sorted)
        cout << x << " ";

    // -------------------
    // DESC (без сортування)
    // -------------------

    cout << "\n\nSorted DESC:\n";
    for (int i = sorted.size() - 1; i >= 0; i--)
        cout << sorted[i] << " ";

    // -------------------
    // вводимо n
    // -------------------

    int n;
    cout << "\n\nInput group size n: ";
    cin >> n;

    // -------------------
    // суми груп ASC
    // -------------------

    vector<double> sumsASC;

    for (int i = 0; i < sorted.size(); i += n) {

        double sum = 0;

        for (int j = i; j < i + n && j < sorted.size(); j++)
            sum += sorted[j];

        sumsASC.push_back(sum);
    }

    cout << "\nGroup sums ASC:\n";
    for (double x : sumsASC)
        cout << x << " ";

    // -------------------
    // суми груп DESC
    // -------------------

    vector<double> sumsDESC;

    for (int i = sorted.size() - 1; i >= 0; i -= n) {

        double sum = 0;

        for (int j = i; j > i - n && j >= 0; j--)
            sum += sorted[j];

        sumsDESC.push_back(sum);
    }

    cout << "\nGroup sums DESC:\n";
    for (double x : sumsDESC)
        cout << x << " ";

    // -------------------
    // Smax і Smin
    // -------------------

    double Smax = sumsASC[0];
    double Smin = sumsASC[0];

    for (int i = 1; i < sumsASC.size(); i++) {

        if (sumsASC[i] > Smax)
            Smax = sumsASC[i];

        if (sumsASC[i] < Smin)
            Smin = sumsASC[i];
    }

    double diff = abs(Smax - Smin);

    cout << "\n\n|Smax - Smin| = " << diff << endl;

    // -------------------
    // пошук повторів (з урахуванням похибки)
    // -------------------

    vector<double> values;
    vector<int> counts;

    for (double v : V) {

        bool found = false;

        for (int j = 0; j < values.size(); j++) {
            if (abs(values[j] - v) < 0.0001) {
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

    cout << "\nRepeats:\n";
    for (int i = 0; i < values.size(); i++)
        cout << values[i] << " -> " << counts[i] << endl;

    // -------------------
    // JSON
    // -------------------

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