#include "functions.h"

int main()
{
    srand(time(0));

    int size;
    int n;

    cout << "Input array size: ";
    cin >> size;

    cout << "Input n value: ";
    cin >> n;

    ofstream out("e.txt");
    ofstream jout("data.json");

    vector<int> v1(size);
    vector<int> v2;

    for (int i = 0; i < size; i++)
    {
        v1[i] = rand() % 99 + 1;
    }

    cout << "Array V1 elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    out << "Summed numbers:" << endl;
    for (int i = 0; i < v1.size(); i += n)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i + j < v1.size()) {
                sum += v1[i + j];
            }
        }
        out << sum << endl;
    }
    cout << endl;

    sortAsc(v1);
    cout << "Array V1 sorted (ASC): ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }

    int sum2 = sumOfElements(v1);
    cout << endl << "Sum of elements (ASC): " << sum2 << endl << endl;

    sortDesc(v1);
    cout << "Array V1 sorted (DESC): ";
    for (int i = 0; i < size; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl << "Sum of elements (DESC): " << sumOfElements(v1) << endl << endl;

    vector<int> copyV1 = v1;
    rmDuplicates(v1, v2);

    int sum3 = sumOfElements(v2);
    cout << endl;

    cout << "Difference of sums S3 - S2: " << sum3 - sum2 << endl;

    int sizeV2 = v2.size();
    int duplicatesCount = size - sizeV2;

    cout << "Difference of arrays |V1 - V2|: ";
    printDifference(copyV1, v2);
    cout << endl;

    JsonOut(jout, sum2, sum3, duplicatesCount, v1, v2);

    out.close();
    jout.close();

    return 0;
}