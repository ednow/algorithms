//
// Created by ednow on 2021/6/25.
//
#include <fstream>
#include "gtest/gtest.h"
#include "queue"
#include "map"
#include "list"
#include "vector"
#include "nlohmann/json.hpp"

using namespace std;

// 返回
//list<int> Solution(){
//
//}

//json

TEST(TestCase, test_PTA_1004) {
    using json = nlohmann::json;
//    std::ifstream i("data.json");
//    json j;
//    j.push_back("foo");
//    j.push_back(1);
//    j.push_back(true);
//
//// also use emplace_back
//    j.emplace_back(1.78);
//
//// iterate the array
//    for (auto & it : j) {
//        std::cout << it << '\n';
//    }
    std::ifstream i("data.json");
    json j;
//    i >> j;
//https://github.com/nlohmann/json/issues/2066
    std::cout << i.rdbuf();
}