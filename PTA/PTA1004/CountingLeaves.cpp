//
// Created by ednow on 2021/6/25.
//
#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"

#include "queue"
#include "map"
#include "list"
#include "vector"
using namespace std;

// 将int定义为long long int
//#define int long long int
// 一个树的数据结构
typedef vector<list<int>> Tree; // 树的孩子表示法
typedef struct queueItem {
    int label;
    int level;
}item; //{节点编号:层数}

// 进行层次遍历,返回每一层的叶子节点数
map<int,int, greater<>>
solution(Tree & tree){
    map<int,int, greater<>> answer;
    queue<item> q;
    int childLevel = 0;
    // 第一个节点在第一层
    item head = {.label=1, .level=1};
    q.push(head); // 先push根节点进去
    while (!q.empty()){
        head = q.front(); // 队列的头元素
        if (tree[head.label].empty()){ // 检查头元素是不是叶子节点
            answer[head.level]++; // 头元素所在层的叶子节点数+1
        } else { // 让头元素的孩子节点进入队列
            childLevel = head.level + 1;
            for(auto & child : tree[head.label]){
                q.push(item{.label=child, .level=childLevel});
            }
        }
        q.pop();
    }
    return answer;
}


string summit(){
    string s, name;
    char **end = nullptr;
    // N:节点数, M:非叶子节点的数量, parent:父亲节点的编号,label:孩子节点编号, children:孩子的数量
    int N = int(), M=0,  label = 0, parent=0, children = 0;
    cin >> N >> M;
    Tree tree = Tree(N,list<int>());
    do {
        cin >> name >> children;
        parent = strtol(name.c_str(), end, 2);
        do {
            cin >> name;
            label = strtol(name.c_str(), end, 2);
            tree[parent].push_back(label);
        } while (--children); // 该节点还有孩子
    } while (--M); // 还有非叶子节点
    map<int, int, greater<>> answer = solution(tree);
    for(auto & it :answer){
        s += to_string(it.second);
    }
    return s;
}

int Main(){
    cout << summit();
    return 0;
}

TEST(TestCase, test_PTA_1004) {
    using json = nlohmann::json;
    ifstream in("../PTA/PTA1004/data.json");
    json j;
    in >> j;
//    istringstream oss(to_string(j[0]["data"]));
////    cout << to_string(j[0]["data"]);
////    printf("%s", j[0]["data"]);
//    cin.rdbuf(oss.rdbuf());
//    ASSERT_EQ(j[0]["answer"], summit());
//    Main();
    ASSERT_EQ(j[0]["answer"], summit());
}
