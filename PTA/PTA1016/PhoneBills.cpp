//
// Created by ednow on 2021/7/19.
//

#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"
#include <cstdio>
#include <iostream>
#include <string>



#include "list"
#include "map"
#include "algorithm"
#include "string"
#include "vector"
#include <iostream>
#include <sstream>
#include <utility>
#include <iterator>
#include "iomanip"
#include <regex>
#include <numeric>

using namespace std;

typedef struct record_{
    vector<int> date{4, 0};  // 日期[1,2,2,24]代表1月2号2点钟24分钟
    string status;  // 状态,“off-line”,"on-line"

}record;

typedef struct one_bill{
    vector<string> bills;  // 每一条账单字符串
    int total{};  // 总的金额
} bill;


int PhoneBills(){
    int recordsNum{}, hour{}, minute{}, day{}, rate{}, month{};  // 记录的条数
    string result;  // 最后输出的字符串，防止反复io造成的超时
    map<string, vector<record>> records;
    vector<int> rates(24, 0); // 不能使用rates{24, 0}来初始化，这样子相当于初始化两个元素
    string line;
    for (int i = 0; i < 24; ++i) {
        cin >> rates[i];
    }
    map<string, bill> bills;
    cin >> recordsNum;
    regex ws_re(" ");
    getline(cin, line);  // 会多一个空行？？？
    while (recordsNum--){
        getline(cin, line);
        // 将line按照空格分开
        vector<string> strings(std::sregex_token_iterator(line.begin() ,line.end(),ws_re,-1),std ::sregex_token_iterator());
        sscanf(strings[1].c_str(), "%d:%d:%d:%d", &month, &day, &hour, &minute);
        records[strings[0]].push_back(record{.date{month, day, hour, minute}, .status{strings[2]}});
    }

    // start遍历的记录指针，onLine上线的下标，offLine下线的下标,temp循环用的记录变量
    int start{}, onLine{}, offLine{}, temp{}, bill{}, last{};
    ostringstream tempStr;
    for (auto & one: records) {
        // 对通话记录的时间排序
        sort(one.second.begin(), one.second.end(),[](auto a, auto b){
            if (a.date[0] != b.date[0]) return a.date[0] < b.date[0];
            if (a.date[1] != b.date[1]) return a.date[1] < b.date[1];
            if (a.date[2] != b.date[2]) return a.date[2] < b.date[2];
            if (a.date[3] != b.date[3]) return a.date[3] < b.date[3];
            return true;  // 位置不变
        });

        start = 0;
        while (start < one.second.size()-1){   // 这名用户的通话记录没有被遍历完
            onLine = -1;  // 先假设找不到一条上线记录
            offLine = -1; // 先假设找不到一条对应的下线记录

            // 顺着之前的查找指针，找到下一条onLine的记录
            for (temp = start; temp < one.second.size(); ++temp) {
                if (one.second[start].status == "on-line"){
                    onLine = temp;
                    break;
                }
            }

            if (onLine == -1){ // 全是off-line，没有合法的通话记录
                continue;
            } else{
                for (temp = onLine + 1; temp < one.second.size(); ++temp) {
                    if (one.second[temp].status == "on-line"){ // 上一天on-line没有pair off-line,遇到的新的onLine，更新onLine
                        onLine = temp;
                    } else{  // 找到了一条off-line，计算账单
                        offLine = temp;
                        bill = 0; // 本次通话的费用
                        last = 0; // 本次通话的时长
                        if (one.second[onLine].date[1] == one.second[offLine].date[1]){ // 如果在同一天
                            if (one.second[onLine].date[2] == one.second[offLine].date[2]){ // 如果在同一天的同一个小时
                                last += (one.second[onLine].date[3] - one.second[offLine].date[3]);
                                bill += last * rates[one.second[onLine].date[2]];
                            } else{ // 同一天不同小时
                                //先求出on-line那个小时花的钱
                                temp = 60 - one.second[onLine].date[3];
                                bill += temp * rates[one.second[onLine].date[2]];
                                last += temp;
                                // 再求出off-line的时候，花的钱
                                bill += one.second[onLine].date[3] * rates[one.second[onLine].date[2]];
                                last += one.second[onLine].date[3];
                                // 求出（on-line，off-line）之间小时的话费
                                for (temp = one.second[onLine].date[2] + 1; temp < one.second[offLine].date[2]; ++temp) {
                                        bill += 60 * rates[temp];
                                        last += 60;
                                    }
                                }
                        }else{// 不在同一天
                            // 把on-line 那一天的钱结了
                            // 计算on-line 那个小时的话费(telephone bill)
                            temp = 60 - one.second[onLine].date[3];
                            bill += temp * rates[one.second[onLine].date[2]];
                            last += temp;

                            // 结算那一天剩下的小时的话费
                            for (temp = one.second[onLine].date[2] + 1; temp < 24; ++temp) {
                                bill += 60 * rates[temp];
                                last += 60;
                            }

                            // 把off-line 那一天的钱结了
                            // 计算on-line 那个小时的话费(telephone bill)
                            bill += one.second[offLine].date[3] * rates[one.second[offLine].date[2]];
                            last += one.second[offLine].date[3];

                            // 结算那一天剩下的小时的话费
                            for (temp = 0; temp < one.second[offLine].date[2]; ++temp) {
                                bill += 60 * rates[temp];
                                last += 60;
                            }

                            // 中间一个有多少天
                            temp = one.second[offLine].date[2] - one.second[onLine].date[2] - 1;
                            last += temp * 24 * 60;
                            bill += temp * accumulate(rates.begin(), rates.end(), 0) * 60;
                        }
                        // 将算出来的结果更新到bills里面
                        bill /= 100;
                        bills[one.first].total += bill;
//                        tempStr << setfill('0') << setw(2) 
//                        << one.second[onLine].date[0] << ":"
//                        << one.second[onLine].date[1] << ":"
//                        << one.second[onLine].date[2] << ":"
//                        << one.second[onLine].date[3] << " ";
//                        
//                        tempStr << setfill('0') << setw(2)
//                                << one.second[offLine].date[0] << ":"
//                                << one.second[offLine].date[1] << ":"
//                                << one.second[offLine].date[2] << ":"
//                                << one.second[offLine].date[3];

                        tempStr << setfill('0') << setw(2) << one.second[onLine].date[0];
                        tempStr << ":";
                        tempStr << setfill('0') << setw(2) << one.second[onLine].date[1];
                        tempStr << ":";
                        tempStr << setfill('0') << setw(2) << one.second[onLine].date[2];
                        tempStr << ":";
                        tempStr << setfill('0') << setw(2) << one.second[onLine].date[3];
                        tempStr << " ";
                        tempStr << setfill('0') << setw(2) << one.second[offLine].date[0];
                        tempStr << ":";
                        tempStr << setfill('0') << setw(2) << one.second[offLine].date[1];
                        tempStr << ":";
                        tempStr << setfill('0') << setw(2) << one.second[offLine].date[2];
                        tempStr << ":";
                        tempStr << setfill('0') << setw(2) << one.second[offLine].date[3];
                        tempStr << " ";
                        tempStr << last << ' ';
                        tempStr << '$' << setprecision(2) << bill;
                        bills[one.first].bills.push_back(tempStr.str());
                        tempStr.clear();
                    }
                }
            }
            if (onLine != -1){
                start = offLine;
            } else{
                break; // 这个人的记录全是online的记录
            }
        }
    }

    tempStr.clear();
    for (const auto & one: bills) {
        result += one.first + ' ';
        for (const auto & str:one.second.bills) {
            result += str + '\n';  // 拼接每一次通话的话费的字符串
        }
        tempStr << setprecision(2) << one.second.total;
        result += "Total amount: " + tempStr.str() + '\n';
        tempStr.clear();
    }

    cout << result;
    return 0;
}

TEST(TestCase, test_PTA_1016) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1016/data.json");
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

//        replace_all(s, "\n", " ");
        istringstream oss(s);
        cin.rdbuf(oss.rdbuf());  // 将测试用例读进cin

        std::stringstream   redirectStream;
        std::streambuf*     oldbuf  = std::cout.rdbuf( redirectStream.rdbuf() );

//        freopen(fmemopen(s.c_str(), s.size(), "r"), "r", stdin);  // 将测试用例读进stdin

        PhoneBills();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}