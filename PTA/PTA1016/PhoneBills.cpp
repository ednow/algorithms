//
// Created by ednow on 2021/7/19.
//

#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <unistd.h>
//#include "stdio.h"


#include "list"
#include "map"
#include "string"
#include "vector"
#include <iostream>
#include <sstream>
#include <utility>
#include <iterator>
#include <regex>

using namespace std;

typedef struct record_{
    vector<int> date{4, 0};  // 日期[1,2,2,24]代表1月2号2点钟24分钟
    string status;  // 状态,“off-line”,"on-line"
}record;


int PhoneBills(){
    int recordsNum{}, hour{}, minute{}, day{}, rate{}, month{};  // 记录的条数
    string result;  // 最后输出的字符串，防止反复io造成的超时
    map<string, list<record>> records;
    vector<int> rates(24, 0); // 不能使用rates{24, 0}来初始化，这样子相当于初始化两个元素
    string line;
    for (int i = 0; i < 24; ++i) {
        cin >> rates[i];
    }

    cin >> recordsNum;
    regex ws_re(" ");
    getline(cin, line);  // 会多一个空行？？？
    while (recordsNum--){
        getline(cin, line);
        vector<string> strings(std::sregex_token_iterator(line.begin() ,line.end(),ws_re,-1),std ::sregex_token_iterator());
        sscanf(strings[1].c_str(), "%d:%d:%d:%d", &month, &day, &hour, &minute);
        records[strings[0]].push_back(record{.date{month, day, hour, minute}, .status{strings[2]}});
    }
    return 0;
}

TEST(TestCase, test_PTA_1016) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1016/data.json");
    in >> j;
    ifstream configFile("../config.json");
    configFile >> config;
    vector<map<string, string>> testcases;
    //    &config
    copy_if (j.begin(), j.end(), std::back_inserter(testcases), [&](auto i){return i["id"]== config["testCaseId"];} );
    if (testcases.empty()){
        testcases = j.get<vector<map<string, string>>>();
    }
    for (auto & testcase :testcases) {
        cout << testcase["data"];
        string s = testcase["data"];

//        replace_all(s, "\n", " ");
        istringstream oss(s);
        cin.rdbuf(oss.rdbuf());  // 将测试用例读进cin

        std::stringstream   redirectStream;
        std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

//        freopen(fmemopen(s.c_str(), s.size(), "r"), "r", stdin);  // 将测试用例读进stdin

        PhoneBills();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}