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

// 一颗树的孩子
typedef struct {
    int label; // 编号
    int level; // 所在层数
} child;

// 一个树的数据结构
typedef struct TreeStructure{
    vector<list<child>> nodes; // 树的孩子表示法
    int depth{}; //这课树的深度
} Tree;

// 进行层次遍历,返回每一层的叶子节点数
vector<int> solution(Tree & t){
    vector<list<child>> tree = t.nodes;
    vector<int> answer(t.depth,0) ;
    queue<child> q;
    child head;
    q.push(tree[0].front()); // 先push根节点进去
    while (!q.empty()){
        head = q.front(); // 队列的头元素
        if (tree[head.label].empty()){ // 检查头元素是不是叶子节点
            answer[head.level]++; // 头元素所在层的叶子节点数+1
        } else { // 让头元素的孩子节点进入队列
            for(auto & child : tree[head.label]){
                q.push(child);
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
    Tree tree = {.nodes = vector<list<child>>(N, list<child>()), .depth=0};
    tree.nodes[0].de
    do {
        cin >> name >> children;
        parent = strtol(name.c_str(), end, 2);
        do {
            cin >> name;
            label = strtol(name.c_str(), end, 2);
            tree[parent]
            children--;
        } while (children>0);
        N--;
    } while (N > 0);

//    copy(my_vector.begin(), my_vector.end(), ostream_iterator<int>(result, " "));
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
    istringstream oss(to_string(j[0]["data"]));
    cin.rdbuf(oss.rdbuf());
    ASSERT_EQ(j[0]["answer"], summit());
}


