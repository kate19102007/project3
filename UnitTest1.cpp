#include "pch.h"
#include "CppUnitTest.h"
#include "Header.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
    TEST_CLASS(UnitTest1) {
public:

    TEST_METHOD(TestSortASC) {
        vector<int> v = { 3, 1, 2 };
        vector<int> res = sortASC(v);
        Assert::AreEqual(1, res[0]);
        Assert::AreEqual(2, res[1]);
        Assert::AreEqual(3, res[2]);
    }

    TEST_METHOD(TestSortDESC) {
        vector<int> v = { 1, 3, 2 };
        vector<int> res = sortDESC(v);
        Assert::AreEqual(3, res[0]);
        Assert::AreEqual(2, res[1]);
        Assert::AreEqual(1, res[2]);
    }

    TEST_METHOD(TestGroupSums) {
        vector<int> v = { 1, 2, 3, 4, 5, 6 };
        vector<int> res = groupSums(v, 2);
        Assert::AreEqual(3, res[0]);  // 1+2
        Assert::AreEqual(7, res[1]);  // 3+4
        Assert::AreEqual(11, res[2]); // 5+6
    }

    TEST_METHOD(TestDiffMaxMin) {
        vector<int> sums = { 10, 30, 20 };
        Assert::AreEqual(20, diffMaxMin(sums));
    }
    };
}
