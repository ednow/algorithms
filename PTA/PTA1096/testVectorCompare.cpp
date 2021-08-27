//
// Created by ednow on 2021/8/27.
//


#include "utils.h"
#include "iostream"
#include "vector"

// vector会优先比较值，然后比较长度



TEST(test, a){
    vector<int> a={1,2};
    vector<int> b={2,1};
    cout << (a < b);
    // 1
}


TEST(test, b){
    vector<int> a={2};
    vector<int> b={1,1};
    cout << (a < b);
    //0
}


TEST(test, c){
    vector<int> a={2};
    vector<int> b={2,1};
    cout << (a < b);
    //1
}