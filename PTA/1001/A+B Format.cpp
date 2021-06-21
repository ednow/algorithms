//
// Created by lnd on 2021/6/21.
//

#include <string>
#include "gtest/gtest.h"

using namespace std;

string num_readable(int num, string S, int & pos){
    if (num == 0){
        pos = pos + 1;
        return S;
    }
    int temp = num % 10;
    S = num_readable(num /= 10, S, pos);
    S.append(to_string(temp));
    if (pos % 3 == 0 && pos != 0){
        S.append(",");
    }
    pos = pos + 1;
    return S;
}


string solution(int A, int B){
    string S;
    int num = A+B, pos=0;
    if (num < 0 ){
        S.append("-");
    }
    return num_readable(abs(num), S, pos);

}



TEST(TestCase, solution_A_plus_B) {
    ASSERT_EQ("-999,991", solution(-1000000,9));
}
