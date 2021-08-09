//
// Created by ednow on 2021/8/9.
//

#include "WaitingInLine.h"

#include "iostream"
#include "ios"
#include "queue"
#include "map"

using namespace std;


int WaitingInLine(){

    return 0;
}



TEST(TestCase, test_PTA_1014) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1014/data.json");
    in >> j;
    ifstream configFile("../config.json");
    configFile >> config;
    vector<map<string, string>> testcases;
    //    &config
    copy_if(j.begin(), j.end(), std::back_inserter(testcases), [&](auto i) { return i["id"] == config["testCaseId"]; });
    if (testcases.empty()) {
        testcases = j.get<vector<map<string, string>>>();
    }
    for (auto &testcase :testcases) {
        cout << "--------------------------------" << endl;
        cout << "testCaseId:" << testcase["id"] << " testing" << endl;

        string s = testcase["data"];
        istringstream oss(s);
        cin.rdbuf(oss.rdbuf());  // 将测试用例读进cin

        std::stringstream redirectStream;
        std::streambuf *oldbuf = std::cout.rdbuf(redirectStream.rdbuf());

        WaitingInLine();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}