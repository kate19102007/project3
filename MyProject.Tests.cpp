
#include "CppUnitTest.h"
#include "functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PositiveTests 
{
    TEST_CLASS(SortingAndSumTests)
    {
    public:

        // Тест 1: Перевірка суми масиву
        TEST_METHOD(TestSumCalculation)
        {
            std::vector<int> v = { 10, 20, 30, 40 };
            int expected = 100;
            int actual = sumOfElements(v);

            Assert::AreEqual(expected, actual);
        }

        // Тест 2: Перевірка сортування за зростанням (ASC)
        TEST_METHOD(TestSortAscending)
        {
            std::vector<int> v = { 9, 1, 5 };
            std::vector<int> expected = { 1, 5, 9 };

            sortAsc(v);

            for (size_t i = 0; i < v.size(); i++) {
                Assert::AreEqual(expected[i], v[i]);
            }
        }

        // Тест 3: Перевірка видалення дублікатів (кількість)
        TEST_METHOD(TestUniqueCount)
        {
            std::vector<int> v = { 7, 7, 8, 9, 9 };
            std::vector<int> unique;
            rmDuplicates(v, unique);

            size_t expectedSize = 3; // Має залишитись {7, 8, 9}
            Assert::AreEqual(expectedSize, unique.size());
        }
    };
}