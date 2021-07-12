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
//# include "map"
using namespace std;

#define MAXLEN  100000

struct {
    int address{};
    string data;
    bool isVisited = false;
    int next{};
} nodes[MAXLEN];

int sharing2Main(){
    // head1，第一个列表的第一个节点，head2：第二个列表的第一个节点，
    // nodeNum,内存块的个数
    int head1=0, head2=0, nodeNum=0, address=0, next=0;
    string data, result;
    cin >> head1 >> head2 >> nodeNum;
    for (int i = 0; i < nodeNum; ++i) {
        cin >> address >> data >> next;
        nodes[address].data = data;
        nodes[address].next = next;
        nodes[address].address = address;
    }
    for (int i = head1; i != -1; i = nodes[i].next) {
        nodes[i].isVisited = true;
    }

    for (int i = head2; i != -1; i = nodes[i].next) {
        if (nodes[i].isVisited){
            cout << setw(5) << setfill('0') <<  to_string(nodes[i].address) << endl;
            return 0;
        }
    }

    cout <<  "-1\n";
    return 0;
}



TEST(TestCase, test_PTA_1032_2) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1032/data.json");
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
        sharing2Main();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}