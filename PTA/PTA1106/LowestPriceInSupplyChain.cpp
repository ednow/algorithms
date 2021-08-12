//
// Created by ednow on 2021/8/12.
//

#include "LowestPriceInSupplyChain.h"
#include "ios"
#include "iostream"
#include "vector"
#include "queue"
#include "limits"
#include "iomanip"
#include "cmath"

using namespace std;

// 队列中的元素
typedef struct item_ {
    // 节点所在层次
    int level{};
    // 节点编号
    int label{};
}item;

int LowestPriceInSupplyChain(){
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    // nodesNum节点数
    int nodesNum{};
    // price:单价，rate：每一层增长的百分比
    double price{}, rate{};
    cin >> nodesNum >> price >> rate;
    rate /= 100;
    // 孩子兄弟表示法
    vector<vector<int>> tree(nodesNum);
    int tempNode{};
    int tempNodesNum{};
    for (int i = 0; i < nodesNum; ++i) {
        cin >> tempNodesNum;
        if (tempNodesNum > 0){
            while (tempNodesNum--){
                cin >> tempNode;
                tree[i].push_back(tempNode);
            }
        }
    }
    // 队列
    queue<item> q;
    q.push(item{.level=0, .label=0});
    // 最小的层数
    int minLevel = INT32_MAX;
    // 最小层数的数量
    int minLevelNums{};
    // 开始层次遍历
    while (!q.empty()){
        // 叶子节点
        if (tree[q.front().label].empty()){
            if (q.front().level < minLevel){
                minLevel = q.front().level;
                minLevelNums = 0;  // 下面的if会使其+1
            }

            if (q.front().level == minLevel){
                minLevelNums++;
            }
        } else{
            for (const auto & child: tree[q.front().label]) {
                q.push(item{.level = q.front().level + 1, .label = child});
            }
        }
        q.pop();
    }

    cout << setprecision(4) << fixed << price * pow(1 + rate, minLevel) << " ";
    cout << minLevelNums << endl;

    return 0;
}


TEST(TestCase, test_PTA_1106) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1106/data.json");
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

        LowestPriceInSupplyChain();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}