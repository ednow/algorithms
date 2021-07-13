//
// Created by ednow on 2021/7/13.
//
#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"

#include "algorithm"
#include "vector"
#include "ios"
#include "iomanip"
#include "iostream"

using namespace std;

typedef struct node_ {
    int address{};
    int key{};
    int next{};
    bool isPrinted{false};
}node;


int DeduplicationOnLinkedList(){
//    ios::sync_with_stdio(false);
    int head{}, nodeNum{},address{}, key{}, next{}, pointer{}, nextPointer{};
    bool isNext = false;  // 是否还有下一个节点
    vector<bool> keys(10001, false);
    vector<node> nodes(100000);

    cin >> head >> nodeNum;

    // 读取数据
    while (nodeNum-- > 0){
        cin >> address >> key >> next;
        nodes[address].address = address;
        nodes[address].key = key;
        nodes[address].next = next;
    }

    // 去重输出列表
    for (pointer = head; pointer != -1 ;pointer = nextPointer) {
        keys[abs(nodes[pointer].key)] = true; // 当前要打印的节点标记为已经输出过

        for (int i = nodes[pointer].next; i != -1 ; i = nodes[i].next) {  // 找到下一个没有出现过的节点
            if (!keys[abs(nodes[i].key)]){  // 如果该值未出现过
                isNext = true;
                nextPointer = i;
                next = nodes[i].address;  // 链表还要连在一起
                break;
            }
        }

        if (isNext){ // 还有下一个
            cout << setw(5) << setfill('0') << nodes[pointer].address << ' ';
            cout << nodes[pointer].key << ' ';
            cout << setw(5) << next << endl;

            keys[abs(nodes[pointer].key)] = true;
            nodes[pointer].isPrinted = true;

        } else{
            cout << setw(5) << setfill('0') << nodes[pointer].address << ' ';
            cout << nodes[pointer].key << ' ';
            cout << -1 << endl;
            break; // 结束输出
        }

        // 重置有没有下一个
        isNext = false;
    }

    isNext = false;
//    找到第一个没有输出的节点
    for (pointer = head; pointer != -1; pointer = nodes[pointer].next){
        if (!nodes[pointer].isPrinted){  // 如果这个节点未被输出
            isNext = true;
            break;
        }
    }

    if(isNext){
        isNext = false;
    } else{
        return 0;
    }

    // 输出去掉的节点
    for (; pointer != -1; pointer = nextPointer) {
        nodes[pointer].isPrinted = true; // 当前要打印的节点标记为已经输出过
        for (int i = nodes[pointer].next; i != -1 ; i = nodes[i].next) {  // 找到下一个没有输出过的节点
            if (!nodes[i].isPrinted){  // 如果这个节点未被输出
                isNext = true;
                nextPointer = i;
                next = nodes[i].address;  // 链表还要连在一起
                break;
            }
        }

        if (isNext){ // 还有下一个
            cout << setw(5) << setfill('0') << nodes[pointer].address << ' ';
            cout << nodes[pointer].key << ' ';
            cout << setw(5) << next << endl;
        } else{  // next要输出-1
            cout << setw(5) << setfill('0') << nodes[pointer].address << ' ';
            cout << nodes[pointer].key << ' ';
            cout << -1 << endl;
            break; // 结束输出
        }


    }

    return 0;
}


TEST(TestCase, test_PTA_1097) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1097/data.json");
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
        DeduplicationOnLinkedList();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}