#include "pch.h"
#include "CppUnitTest.h"
#include "../27.03.26/func.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
    TEST_CLASS(SortTests)
    {
    public:

        TEST_METHOD(TestSortASC)
        {
            vector<double> asc = { 5.5, 1.1, 4.4, 2.2, 8.8 };
            vector<double> expected = { 1.1, 2.2, 4.4, 5.5, 8.8 };

            sortASC(asc);

            for (size_t i = 0; i < expected.size(); i++) {
                Assert::AreEqual(expected[i], asc[i], 0.0001);
            }
        }

        TEST_METHOD(TestCalculateGroupSumsASC)
        {
            vector<double> data = { 1, 2, 3, 4, 5 };
            int n = 2;

            vector<double> expected = { 3, 7, 5 };

            vector<double> result = calculateGroupSumsASC(data, n);

            Assert::AreEqual(static_cast<int>(expected.size()), static_cast<int>(result.size()));

            for (size_t i = 0; i < expected.size(); i++) {
                Assert::AreEqual(expected[i], result[i], 0.0001);
            }
        }

        TEST_METHOD(TestFindRepeats)
        {
            vector<double> V = { 10.1, 20.2, 10.1, 30.3, 20.2, 10.1 };
            vector<double> values;
            vector<int> counts;

            findRepeats(V, values, counts);

            bool found = false;
            for (size_t i = 0; i < values.size(); i++) {
                if (abs(values[i] - 10.1) < 0.0001) {
                    Assert::AreEqual(3, counts[i]);
                    found = true;
                }
            }

            Assert::IsTrue(found);
        }

        TEST_METHOD(TestFailedExample)
        {
            vector<double> data = { 10, 10, 10 };
            int n = 3;

            double expected_wrong = 999;

            vector<double> result = calculateGroupSumsASC(data, n);

            Assert::AreEqual(expected_wrong, result[0], 0.0001); 
        }
    };
}
