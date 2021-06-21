//
// Created by lnd on 2021/6/21.
//

#include <string>
#include "gtest/gtest.h"
#include <iostream>

using namespace std;


string solution(int A, int B) {
    int num = A + B;
    string S(to_string(abs(num)));
    unsigned long long len = S.length();

    while (len >= 4) {
        len -= 3;
        S.insert(len, ",");
    }

    if(num < 0) {
        S.insert(0, "-");
    }

    return S;
}

//int A = 0, B = 0;
//cin>>A
//scanf("")

TEST(TestCase, solution_A_plus_B) {
    ASSERT_EQ("-999,991", solution(-1000000, 9));
    ASSERT_EQ("0", solution(-1, 1));
    ASSERT_EQ("300", solution(300, 0));
    ASSERT_EQ("1,300", solution(1300, 0));
}
