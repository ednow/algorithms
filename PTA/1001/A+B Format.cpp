//
// Created by lnd on 2021/6/21.
//

#include <string>
#include "gtest/gtest.h"

using namespace std;


string solution(int A, int B){
    string S(to_string(A+B));
    unsigned long long len = S.length();
    while (len > 4){
        len -= 3;
        S.insert(len, ",");
    }
    return S;
}



TEST(TestCase, solution_A_plus_B) {
    ASSERT_EQ("-999,991", solution(-1000000,9));
}
