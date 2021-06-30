//
// Created by ednow on 2021/6/25.
//
#include "gtest/gtest.h"
#include "queue"
#include "map"
#include "list"
#include "vector"
#include <iostream>
#include <string>
using namespace std;

// 将int定义为long long int
//#define int long long int
// 一个树的数据结构
typedef vector<list<int>> Tree; // 树的孩子表示法
typedef struct queueItem {
    int label;
    int level;
}item; //{节点编号:层数}

int SlimMain() {
    string s, name;
    char** end = nullptr;
    // N:节点数, M:非叶子节点的数量, parent:父亲节点的编号,label:孩子节点编号, children:孩子的数量
    int N = 0, M = 0, label = 0, parent = 0, children = 0;
    cin >> N >> M;
    //    scanf("%d %d", &N, &M);
    Tree tree = Tree(N + 1);
    while (M-- > 0) {
        cin >> name >> children;

        parent = strtol(name.c_str(), end, 10);
        do {
            cin >> name;
            label = strtol(name.c_str(), end, 10);
            tree[parent].push_back(label);
        } while (--children > 0); // 该节点还有孩子
    } ; // 还有非叶子节点

    // 进行层次遍历
    map<int, int> answer;
    queue<item> q;
    int childLevel = 0;
    // 第一个节点在第一层
    item head = { .label = 1, .level = 1 };
    q.push(head); // 先push根节点进去
    while (!q.empty()) {
        head = q.front(); // 队列的头元素
        if (tree[head.label].empty()) { // 检查头元素是不是叶子节点
            answer[head.level]++; // 头元素所在层的叶子节点数+1
        }
        else { // 让头元素的孩子节点进入队列
            childLevel = head.level + 1;
            for (auto& child : tree[head.label]) {
                q.push(item{ .label = child, .level = childLevel });
            }
        }
        q.pop();
    }
    if (answer.find(1) == answer.end()) {
        s += "0";
    }
    for (int i = 2; i <= childLevel; ++i) {
        if (answer.find(i) == answer.end()) {
            s += " 0";
        }
        else {
            s += " " + to_string(answer[i]);
        }

    }
    if (childLevel == 0)
    {
        s += "1";
    }


    cout << s << endl;
    return 0;
}




//TEST(TestCase, test_PTA_1004_slim) {
//    Main();
//}