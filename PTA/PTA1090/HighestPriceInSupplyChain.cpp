//
// Created by ednow on 2021/8/12.
//

#include "HighestPriceInSupplyChain.h"
#include "ios"
#include "iostream"
#include "iomanip"
#include "vector"
#include "algorithm" // max_element
#include "cmath"

using namespace std;


int HighestPriceInSupplyChain(){
//    加快读取速度
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    //
    int members{};
    double price{}, rate{};
    cin >> members >> price >> rate;
    rate /= 100;
    // 双亲表示法
    vector<int> tree(members);
    // 每一个
    vector<int> levels(members);
    // 建树
    for (int i = 0; i < members; ++i) {
        cin >> tree[i];
    }

    // 标记所有节点的层次
    int level{};
    // 找到根节点前的临时节点
    int tempNode{};
    for (int i = 0; i < members; ++i) {
        level = 0;
        tempNode = i;
        while (tree[tempNode] != -1){
            tempNode = tree[tempNode];
            level++;
        }
        levels[i] = level;
    }

    auto  maxLevel = *max_element(levels.begin(), levels.end());
    int maxLevelNum{};
    // 找最大节点的个数
    for (int i = 0; i < members; ++i) {
        if(levels[i] == maxLevel){
            maxLevelNum++;
        }
    }

    cout << setprecision(2) << fixed << price * pow(1 + rate, maxLevel) << " ";
    cout << maxLevelNum << endl;


    return 0;
}

TEST(TestCase, test_PTA_1090) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1090/data.json");
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

        HighestPriceInSupplyChain();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}