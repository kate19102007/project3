#include "Header1.h"

void generateVector(vector<int>& V, int size) {
    for (int i = 0; i < size; i++)
        V.push_back(rand() % 100);
}

void printVector(const vector<int>& V, const string& label) {
    cout << label;
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
}

void sortASC(vector<int>& asc) {
    for (int i = 0; i < asc.size(); i++)
        for (int j = 0; j < asc.size() - 1; j++)
            if (asc[j] > asc[j + 1]) {
                int t = asc[j];
                asc[j] = asc[j + 1];
                asc[j + 1] = t;
            }
}

void sortDESC(vector<int>& desc) {
    for (int i = 0; i < desc.size(); i++)
        for (int j = 0; j < desc.size() - 1; j++)
            if (desc[j] < desc[j + 1]) {
                int t = desc[j];
                desc[j] = desc[j + 1];
                desc[j + 1] = t;
            }
}

vector<int> calculateGroupSums(const vector<int>& data, int n) {
    vector<int> sums;
    for (int i = 0; i < data.size(); i += n) {
        int sum = 0;
        for (int j = i; j < i + n && j < data.size(); j++)
            sum += data[j];
        sums.push_back(sum);
    }
    return sums;
}

void findRepeats(const vector<int>& V, vector<int>& values, vector<int>& counts) {
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
}

void saveToJSON(const vector<int>& values, const vector<int>& counts, const vector<int>& sumsASC, const vector<int>& sumsDESC, int diff) {
    json j;
    for (int i = 0; i < values.size(); i++)
        j["repeats"][to_string(values[i])] = counts[i];

    j["group_sums_ASC"] = sumsASC;
    j["group_sums_DESC"] = sumsDESC;
    j["difference"] = diff;

    ofstream file("result.json");
    file << j.dump(4);
    file.close();
}

int main() {
    srand(time(0));

    int size;
    cout << "Input vector size: ";
    cin >> size;

    vector<int> V;
    generateVector(V, size);
    printVector(V, "\nOriginal vector:\n");

    // Сортування
    vector<int> asc = V;
    sortASC(asc);
    printVector(asc, "\n\nSorted ASC:\n");

    vector<int> desc = V;
    sortDESC(desc);
    printVector(desc, "\n\nSorted DESC:\n");

    // Групи
    int n;
    cout << "\n\nInput group size n: ";
    cin >> n;

    vector<int> sumsASC = calculateGroupSums(asc, n);
    printVector(sumsASC, "\nGroup sums ASC:\n");

    vector<int> sumsDESC = calculateGroupSums(desc, n);
    printVector(sumsDESC, "\nGroup sums DESC:\n");

    // Smax і Smin
    int Smax = sumsASC[0];
    int Smin = sumsASC[0];
    for (int i = 1; i < sumsASC.size(); i++) {
        if (sumsASC[i] > Smax) Smax = sumsASC[i];
        if (sumsASC[i] < Smin) Smin = sumsASC[i];
    }
    int diff = abs(Smax - Smin);
    cout << "\n\n|Smax - Smin| = " << diff << endl;

    // Пошук повторів
    vector<int> values;
    vector<int> counts;
    findRepeats(V, values, counts);

    cout << "\nRepeats:\n";
    for (int i = 0; i < values.size(); i++)
        cout << values[i] << " -> " << counts[i] << endl;

    // Збереження
    saveToJSON(values, counts, sumsASC, sumsDESC, diff);
    cout << "\nResults saved to result.json\n";

    return 0;
}