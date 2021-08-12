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
#include "map"
#include "queue"

typedef struct item_ {
    int level{};  // 在哪一层
    int label{};
}item;  // 队列中的元素

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
    // 孩子兄弟表示法
    vector<vector<int>> tree(members + 1);
    // 每一个
    vector<int> levels(members + 1);
    // 建树
    int tempNode{};
    for (int i = 1; i < members + 1; ++i) {
        cin >> tempNode;
        // 注意有0号有-1
        tree[tempNode + 1].push_back(i);

    }

    // 找到根节点前的临时节点
    int  maxLevel{};
    int maxLevelNum{};
    // 层次遍历的时候顺便把最大的节点和节点数给找到
    queue<item> q;
    q.push(item{.level=-1, .label=0});
    while (!q.empty()){
        // 叶子节点
        if (tree[q.front().label].empty()){
            // 如果当前的层次更大，更新最大层次，将最大层次的节点数重置
            if (q.front().level > maxLevel){
                maxLevel = q.front().level;
                maxLevelNum = 0;
            }

            if (q.front().level == maxLevel){
                maxLevelNum ++;
            }

        }else{  // 非叶子节点
            for (const auto a:tree[q.front().label]) {
                q.push(item{
                        .level = q.front().level + 1, // 下一层
                        .label = a
                });
            }
        }

        q.pop();
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