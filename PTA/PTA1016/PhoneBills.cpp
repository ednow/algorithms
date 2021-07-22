//
// Created by ednow on 2021/7/19.
//

#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"

#include "list"
#include "map"
#include "string"
#include "vector"
#include <iostream>
#include <sstream>
#include <utility>
#include <iterator>

using namespace std;

typedef struct record_{
    vector<int> date{4, 0};  // 日期[1,2,2,24]代表1月2号2点钟24分钟
    string status;  // 状态,“off-line”,"on-line"
}record;


int PhoneBills(){
//    vector<int> rates{20, 0};
    int recordsNum{}, hour{}, minute{}, second{}, rate{};  // 记录的条数
    string result, name, status;  // 最后输出的字符串，防止反复io造成的超时
    map<string, list<record>> records;
    vector<int> rates(24, 0); // 不能使用rates{24, 0}来初始化，这样子相当于初始化两个元素
//    string line;
//    getline(cin, line);
//    istringstream this_line(line);
//    istream_iterator<int> begin(this_line), end;
//    vector<int> rates(begin, end); // 每个小时每分钟的价格
    for (int i = 0; i < 24; ++i) {
        cin >> rates[i];
//        scanf("%d ", &rates[i]);
    }

    cin >> recordsNum;
    while (recordsNum--){
        cin >> name >> hour >> minute >> second >> status;
        records[name].push_back(record{.date{hour, minute, second}, .status{status}});
//        records[]
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
        replace_all_distinct(s, "\\n", " ");
        istringstream oss(s);
        cin.rdbuf(oss.rdbuf());  // 将测试用例读进cin
        std::stringstream   redirectStream;
        std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );
        PhoneBills();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}