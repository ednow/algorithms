//
// Created by ednow on 2021/7/15.
//
#include <fstream>
#include "gtest/gtest.h"
#include "nlohmann/json.hpp"
#include "utils.h"

#include "iostream"
#include "ios"
#include "iomanip"
#include "vector"

#include<iostream>
#include<cstring>
#include<algorithm>
struct node{
    int id;
    //A C M E
    int grace[5];
    int rank[5];
}pre[2005];
int n,m;
using namespace std;
int tmp=0;
bool cmp(node x,node y){
    return x.grace [tmp]>y.grace [tmp];
}

int TheBestRank1(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>pre[i].id >>pre[i].grace [1]>>pre[i].grace [2]>>pre[i].grace [3];
        pre[i].grace [0]=(pre[i].grace [1]+pre[i].grace [2]+pre[i].grace [3])/3;
    }
    for(int i=0;i<4;i++){
        tmp=i;
        sort(pre,pre+n,cmp);
        for(int j=0;j<n;j++){
            pre[j].rank [i]=j+1;
        }
        for(int j=1;j<n;j++){
            if(pre[j].grace [i]==pre[j-1].grace[i])
                pre[j].rank [i]=pre[j-1].rank [i];
        }
    }
//	for(int i=0;i<n;i++){
//		cout<<pre[i].id <<endl;
//		for(int j=0;j<4;j++){
//			cout<<pre[i].rank [j]<<" ";
//		}
//		cout<<endl;
//	}
    char cp[5]={'A','C','M','E'};
    while(m--){
        int ID;
        cin>>ID;
        int Min=0;
        int tmp=0;
        bool flag=0;
        for(int i=0;i<n;i++){
            if(pre[i].id ==ID){
                flag=1;
                tmp=i;
                break;
            }
        }
        if(!flag){
            cout<<"N/A"<<endl;
            continue;
        }
        for(int i=1;i<4;i++){
            if(pre[tmp].rank [i]<pre[tmp].rank [Min]){
                Min=i;
            }
        }
        cout<<pre[tmp].rank [Min]<<" "<<cp[Min]<<endl;
    }
    return 0;
}

TEST(TestCase, test_PTA_1012_1) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1012/data.json");
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
        TheBestRank1();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);
    }
}