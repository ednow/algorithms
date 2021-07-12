//
// Created by ednow on 2021/7/12.
//

#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"
#include <sstream>


# include "string"
# include "iostream"
# include "iomanip"
using namespace std;

#define MAX 100000
#define MAXNUM 100001

typedef struct node_{
    int address{};
    int key = MAXNUM;
    int next{};
}node;

int LinkedListSortingMain(){
    int nodeNum=0,head=0, address=0,key=0,next=0,len=0;
    vector<node> nodes(MAX);
    vector<node> list(MAX);
    cin >> nodeNum >> head;
    while (nodeNum-- > 0){
        cin >> address >> key >> next;
        nodes[address].address = address;
        nodes[address].key = key;
        nodes[address].next = next;
    }

    // 建立链表
    for (int pointer=head; pointer != -1 ; pointer = nodes[pointer].next) {
        list[len].address = nodes[pointer].address;
        list[len].key = nodes[pointer].key;
        list[len].next = nodes[pointer].next;
        len++;
    }


    // 排序链表
    partial_sort(list.begin(), list.begin() + len, list.end(), [](auto a, auto b){ return a.key < b.key; });

    list[len].address = -1;
    // 输出
    cout << len << ' ' << setfill('0') << list[0].address << endl;
    for (int i = 0; i  <  len; i++) {
        cout << setw(5) << setfill('0') << list[i].address << ' ';
        cout << list[i].key << ' ';
        if (list[i+1].address == -1){
            cout << -1 << endl;
        } else{
            cout << setw(5) << setfill('0') << list[i+1].address<< endl;
        }

    }

    return 0;
}



TEST(TestCase, test_PTA_1052) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1052/data.json");
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
        LinkedListSortingMain();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}