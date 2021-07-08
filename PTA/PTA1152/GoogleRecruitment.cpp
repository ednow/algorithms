//
// Created by ednow on 2021/6/25.
//
#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"

#include "string"

using namespace std;

bool is_prime(unsigned long long num){
    for(int i = 2 ;i <= num -1;i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}


string summit_1(){
    string num;
    unsigned long long numLen, primeLen;
    cin >> numLen >> primeLen;
    cin >> num;
    for(int i=0;i<numLen-primeLen + 1;i++){
        if (is_prime(stoull(num.substr(i, primeLen)))){
            return num.substr(i, primeLen) + "\n";
        }
    }
    return "404\n";
}

int GoogleMain(){
    cout << summit_1();
    return 0;
}

TEST(TestCase, test_PTA_1152) {
    using json = nlohmann::json;
    ifstream in("../PTA/PTA1152/data.json");
    json j;
    in >> j;
    for (auto & testcase :j) {
        cout << testcase["data"];
        string s = to_string(testcase["data"]);
        s = s.substr(1, s.length() - 2);
        replace_all_distinct(s, "\\n", " ");
        istringstream oss(s);
        cin.rdbuf(oss.rdbuf());
        ASSERT_EQ(testcase["answer"], summit_1());
    }
}
