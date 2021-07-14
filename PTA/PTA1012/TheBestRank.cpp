//
// Created by ednow on 2021/7/14.
//

#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"

int TheBestRank(){

    return 0;
}

TEST(TestCase, test_PTA_1133) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1133/data.json");
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
        TheBestRank();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}