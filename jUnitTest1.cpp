#include "CppUnitTest.h"
#include "../json/Header1.h" // Шлях до вашого хедера

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(SortTests)
    {
    public:

        TEST_METHOD(TestSortASC)
        {
            // Arrange (Підготовка)
            vector<int> asc = { 5, 1, 4, 2, 8 };
            vector<int> expected = { 1, 2, 4, 5, 8 };

            // Act (Дія)
            sortASC(asc);

            // Assert (Перевірка)
            for (size_t i = 0; i < expected.size(); i++) {
                Assert::AreEqual(expected[i], asc[i]);
            }
        }

        TEST_METHOD(TestSortDESC)
        {
            vector<int> desc = { 5, 1, 4, 2, 8 };
            vector<int> expected = { 8, 5, 4, 2, 1 };

            sortDESC(desc);

            for (size_t i = 0; i < expected.size(); i++) {
                Assert::AreEqual(expected[i], desc[i]);
            }
        }

        TEST_METHOD(TestCalculateGroupSums)
        {
            vector<int> data = { 1, 2, 3, 4, 5 };
            int n = 2;
            // Групи: (1+2)=3, (3+4)=7, (5)=5
            vector<int> expected = { 3, 7, 5 };

            vector<int> result = calculateGroupSums(data, n);

            Assert::AreEqual(expected.size(), result.size());
            for (size_t i = 0; i < expected.size(); i++) {
                Assert::AreEqual(expected[i], result[i]);
            }
        }

        TEST_METHOD(TestFindRepeats)
        {
            vector<int> V = { 10, 20, 10, 30, 20, 10 };
            vector<int> values;
            vector<int> counts;

            findRepeats(V, values, counts);

            // Перевіряємо число 10 (має бути 3 рази)
            bool found10 = false;
            for (size_t i = 0; i < values.size(); i++) {
                if (values[i] == 10) {
                    Assert::AreEqual(3, counts[i]);
                    found10 = true;
                }
            }
            Assert::IsTrue(found10);
        }
        TEST_METHOD(TestFailedExample)
        {
            // Цей тест спеціально зроблений так, щоб провалитися
            vector<int> data = { 10, 10, 10 };
            int n = 3;

            // Насправді сума 30, але ми напишемо, що очікуємо 999
            int expected_wrong_sum = 999;

            vector<int> result = calculateGroupSums(data, n);

            // Тест зупиниться тут і покаже помилку, бо 30 != 999
            Assert::AreEqual(expected_wrong_sum, result[0]);
        }
    };
}