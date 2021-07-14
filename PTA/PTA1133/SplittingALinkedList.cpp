//
// Created by ednow on 2021/7/14.
//

#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"

#include "iostream"
#include "ios"
#include "iomanip"
#include "vector"

using namespace std;

#define MAX 100000

typedef struct node_{
    int address{};
    int data{};
    int next{};
}node;


int SplittingALinkedList(){
//    ios::sync_with_stdio(false);
    int head{}, k{}, nodeNum{}, address{}, data{}, next{}, negativeNodesLen{}, lessNodesLen{}, greaterNodesLen{};
    // 题目的要求就是分成
    // negativeNodes(值为负数的节点)，
    // lessNodes(值小于等于k的正数)
    // greaterNodes(值大于k的正数)
    vector<node> nodes(MAX), negativeNodes(MAX), lessNodes(MAX), greaterNodes(MAX);
    cin >> head >> nodeNum >> k;

    // 读入所有节点
    while (nodeNum--){
        cin >> address >> data >> next;
        nodes[address].address = address;
        nodes[address].data = data;
        nodes[address].next = next;
    }

    // 遍历链表，生成3个split的链表
    for (int pointer = head; pointer != -1 ; pointer = nodes[pointer].next) {
        if (nodes[pointer].data < 0){
            negativeNodes[negativeNodesLen].address = nodes[pointer].address;
            negativeNodes[negativeNodesLen].data = nodes[pointer].data;
            negativeNodes[negativeNodesLen].next = nodes[pointer].next;
            negativeNodesLen++;
            // 这样写行吗？
//            negativeNodes[negativeNodesLen] = {nodes[pointer].address, nodes[pointer].data, nodes[pointer].next};
        }else{
            if (nodes[pointer].data <= k){
                lessNodes[lessNodesLen].address = nodes[pointer].address;
                lessNodes[lessNodesLen].data = nodes[pointer].data;
                lessNodes[lessNodesLen].next = nodes[pointer].next;
                lessNodesLen++;
            } else{
                greaterNodes[greaterNodesLen].address = nodes[pointer].address;
                greaterNodes[greaterNodesLen].data = nodes[pointer].data;
                greaterNodes[greaterNodesLen].next = nodes[pointer].next;
                greaterNodesLen++;
            }
        }
        
    }

    // 链接输出negativeNodes
    for (int i = 0; i < negativeNodesLen-1; ++i) {
        cout << setw(5) << setfill('0') << negativeNodes[i].address << ' ';
        cout << negativeNodes[i].data << ' ';
        cout << setw(5) << setfill('0') << negativeNodes[i + 1].address << endl;
    }
    // 最后一个元素，看后面还有没有元素，有元素链接输出
    cout << setw(5) << setfill('0') << negativeNodes[negativeNodesLen-1].address << ' ';
    cout << negativeNodes[negativeNodesLen-1].data << ' ';
    if (negativeNodesLen != 0 && lessNodesLen != 0){  // 有negative node ，lessNodesLen,输出lessNode0号节点地址
        cout << setw(5) << setfill('0') << lessNodes[0].address << endl;
    } else {
        if (negativeNodesLen != 0 && greaterNodesLen != 0){  // 有negative node ，greaterNodesLen,输出greaterNodes0号节点地址
            cout << setw(5) << setfill('0') << greaterNodes[0].address << endl;
        } else{
            cout << -1 << endl;
            return 0;
        }
    }

    // 链接输出lessNodesLen
    for (int i = 0; i < lessNodesLen-1; ++i) {
        cout << setw(5) << setfill('0') << lessNodes[i].address << ' ';
        cout << lessNodes[i].data << ' ';
        cout << setw(5) << setfill('0') << lessNodes[i + 1].address << endl;
    }
    cout << setw(5) << setfill('0') << lessNodes[lessNodesLen-1].address << ' ';
    cout << lessNodes[lessNodesLen-1].data << ' ';
    // 最后一个元素，看后面还有没有元素，有元素链接输出
    if (lessNodesLen != 0 && greaterNodesLen != 0){  // 有negative node ，lessNodesLen,输出lessNode0号节点地址
        cout << setw(5) << setfill('0') << greaterNodes[0].address << endl;
    } else {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < greaterNodesLen-1; ++i) {
        cout << setw(5) << setfill('0') << greaterNodes[i].address << ' ';
        cout << greaterNodes[i].data << ' ';
        cout << setw(5) << setfill('0') << greaterNodes[i + 1].address << endl;
    }
    cout << setw(5) << setfill('0') << greaterNodes[greaterNodesLen-1].address << ' ';
    cout << greaterNodes[greaterNodesLen-1].data << ' ';
    cout << -1 << endl;
    

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
        SplittingALinkedList();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}