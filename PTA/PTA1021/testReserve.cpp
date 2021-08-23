//
// Created by ednow on 2021/8/23.
//

#include "utils.h"
#include "iostream"
#include "vector"

// 测试能不能插入超过reserve数量的元素
// 结论可以正常push_back
TEST(test, push_more_than_reserve){
    vector<int> a;
    a.reserve(5);
    for (int i = 0; i < 5; ++i) {
        a.push_back(i);
    }
    for (auto b: a) {
        cout << b;
    }

    // 01234
}

// 测试reserve后,没有加入元素，但是却试图访问对应下标的元素
// 结论：回返回一个随机数
TEST(test, access_more_than_exact_but_within_reserve){
    vector<int> a;
    a.reserve(5);
    cout << a[2];
    // 22806864
    // 得到一个随机数
}