//
// Created by ednow on 2021/7/1.
//
#ifndef ALGORITHMS_UTILS_H
#define ALGORITHMS_UTILS_H
#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"

using namespace std;

string &replace_all_distinct(string &str, const string &old_value, const string &new_value);

string &replace_all(string &str, const string &old_value, const string &new_value);

//通过FUNC拼接测试函数
#define FUNC(case_id) PTA##case_id();

//执行测试
#define DO_DO_TEST(case_id) using json = nlohmann::json; \
    json j, config;\
    cout << "../PTA/PTA"#case_id"/data.json";          \
    ifstream in("../PTA/PTA"#case_id"/data.json");\
    in >> j;\
    ifstream configFile("../config.json");\
    configFile >> config;\
    vector<map<string, string>> testcases;\
    if (!config["testCaseId"].is_null()){\
            copy_if (j.begin(), j.end(), std::back_inserter(testcases), [&](auto i){return i["id"]== config["testCaseId"];} );\
        } else{\
            copy(j.begin(), j.end(), std::back_inserter(testcases));\
    }\
    if (config["excludeTestCaseIds"].is_array()){\
    testcases.erase(remove_if(testcases.begin(), testcases.end(), [&](auto &a){\
        auto excluded = config["excludeTestCaseIds"].get<vector<string>>();\
        return find(excluded.begin(), excluded.end(), a["id"]) != excluded.end();\
    }), testcases.end());\
    }\
    if (testcases.empty()) {\
    testcases = j.get<vector<map<string, string>>>();\
    }\
    for (auto &testcase :testcases) {\
        cout << "--------------------------------" << endl;\
        cout << "testCaseId:" << testcase["id"] << " testing" << endl;\
        string s = testcase["data"];\
        istringstream oss(s);\
        cin.rdbuf(oss.rdbuf());\
        std::stringstream redirectStream;\
        std::streambuf *oldbuf = cout.rdbuf(redirectStream.rdbuf());\
        FUNC(case_id);\
        ASSERT_EQ(testcase["answer"], redirectStream.str());\
        std::cout.rdbuf(oldbuf);                                              \
        std::cout << "testCaseId:" << testcase["id"] << " passed" << endl;\
        std::cout << "--------------------------------" << endl;\
    }

#define DO_TEST(case_id) DO_DO_TEST(case_id)

#endif //ALGORITHMS_UTILS_H

