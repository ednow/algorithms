//
// Created by ednow on 2021/8/12.
//

#include "TotalSalesOfSupplyChain.h"
#include "ios"
#include "iostream"
#include "queue"
#include "vector"
#include "map"
#include "iomanip"
#include "cmath"

using namespace std;

typedef struct item_ {
    int level{};  // 在哪一层
    int label{};  // 节点编号
}item;  // 队列中的元素

int TotalSalesOfSupplyChain(){
    // members树中节点的个数
    int members{};
    // price原始单价,rate每一层价格提升的比例
    double price, rate;
    cin >> members >> price >> rate;
    rate /= 100;
    // 孩子兄弟表示法
    vector<vector<int>> tree(members);
    // retailers,零售商卖货数
    map<int, int> retailers;

    // 建树

    int childNum{}, temp{};
    for (int i = 0; i < members; ++i) {
        cin >> childNum;
        if(childNum > 0){  // 有孩子
            while (childNum--){
                cin >> temp;
                tree[i].push_back(temp);
            }
        } else{
//            记录这个零售商售卖了的数目
            cin >> temp;
            retailers[i] = temp;
        }

    }

    // 总的零售所得
    double result{};
    // 初始化遍历队列
    queue<item> q;
    q.push(item{.level = 0, .label = 0});
    while (not q.empty()){
        // 是叶子节点
        if (tree[q.front().label].empty()){
            result += price * retailers[q.front().label] * pow(1+rate, q.front().level);
        } else{
            // 让孩子节点入队
            for (const auto child: tree[q.front().label]) {
                q.push(

                item{.level = q.front().level + 1, .label = child}
                );
            }
        }
        q.pop();
    }

    cout << setprecision(1) << fixed << result << endl;

    return 0;
}


TEST(TestCase, test_PTA_1079) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1079/data.json");
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

        TotalSalesOfSupplyChain();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}