//
// Created by ednow on 2021/7/13.
//
#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"
#include <sstream>

#include "string"
#include "iomanip"
#include "vector"
#include "iostream"
#include "algorithm"
#include "ios"
using namespace std;

typedef struct node_{
    int address{};
    int data{};
    int next{};
}node;


int ReversingLinkedList(){
    ios::sync_with_stdio(false);
    int head{}, nodeNum{}, address{}, data{}, next{}, step{}, len{};
    cin >> head >> nodeNum >> step;
    vector<node> list(100000), nodes(100000);
    
    // 读取节点
    while (nodeNum-- > 0){
        cin >> address >> data >> next;
        nodes[address].address = address;
        nodes[address].data = data;
        nodes[address].next = next;
    }
    
    // 建立链表
    for (int i = head; i != -1 ; i = nodes[i].next, len++) {
        list[len].next = nodes[i].next;
        list[len].address = nodes[i].address;
        list[len].data = nodes[i].data;
    }

//    reverse,every step
    for (int i = 1; i * step - 1 < len; i++) {
        reverse(list.begin() + (i - 1) * step, list.begin() + i * step);
    }
    list[len].address = -1;

    // 输出
    for (int i = 0; i < len; i++) {
        cout << setw(5) << setfill('0') << list[i].address << ' ';
        cout << list[i].data << ' ';
        if (list[i+1].address != -1){
            cout << setw(5) << setfill('0') << list[i+1].address << endl;
        } else{
            cout << -1 << endl;
        }
    }

    return 0;
}


TEST(TestCase, test_PTA_1074) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1074/data.json");
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
        ReversingLinkedList();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}