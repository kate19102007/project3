#include "pch.h"
#include "CppUnitTest.h"
#include "functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FailedTests
{
    TEST_CLASS(ManualErrorTests)
    {
    public:

        // Цей тест спеціально провалюється, щоб показати роботу Assert
        TEST_METHOD(TestWithWrongExpectation)
        {
            std::vector<int> v = { 1, 2, 3 }; // Сума реально 6
            int actual = sumOfElements(v);

            // Навмисно вказуємо неправильне очікуване значення
            int wrongExpected = 999;

            // Оскільки 999 не дорівнює 6, тест СТАНЕ ЧЕРВОНИМ
            Assert::AreEqual(wrongExpected, actual, L"Помилка: Реальна сума не збігається з очікуваною (навмисно)!");
        }
    };
}
