//
// Created by ednow on 2021/8/23.
//

#define CASEID 1034

#ifdef CASEID
#define MAIN PTA1034
#else
#define MAIN main
#endif

#include "map"
#include "vector"
#include "iostream"
#include "string"
#include "algorithm"
#include "numeric"

using namespace std;

void dfs(const string& source, map<string, vector<string>> &graph,vector<string> &stack, map<string, bool> &isVisited){
    isVisited[source] = true;
    stack.push_back(source);
    for (const auto &child:graph[source]) {
        if (!isVisited[child]){
            dfs(child, graph, stack, isVisited);
        }
    }
}

int
MAIN(){
    // 图的邻接表表示法
    map<string, vector<string>> graph;
    // 名字 -> 通话时间
    map<string, int> teleTime;
    // 称为head的阈值
    int threshold{};
    // 通话记录数
    int recordNum{};
    cin >> recordNum >> threshold;
    while (recordNum--){
        int t;
        string a, b;
        cin >> a >> b >> t;
        graph[a].push_back(b);
        graph[b].push_back(a);
        teleTime[a] += t;
        teleTime[b] += t;
    }

    // 是否被访问过
    map<string, bool> isVisited;
    for (const auto &a: teleTime) {
        isVisited[a.first] = false;
    }

    // 朋友圈
    // 存放关系网
    vector<vector<string>> friends;

    // 对每一个没有访问过的节点dfs
    for (const auto &a: isVisited) {
        if (!a.second){
            vector<string> stack;
            dfs(a.first, graph, stack, isVisited);
            friends.emplace_back(stack.begin(), stack.end());
        }
    }

    // 保存通话数超过阈值而且人数超过两个的朋友圈
    vector<vector<string>> candidateFriends;
    // 实际上会算两次
    threshold *= 2;
    copy_if(friends.begin(), friends.end(), back_inserter(candidateFriends),[&](const auto &a) {
        return (a.size() > 2) and (accumulate(a.begin(), a.end(), 0, [&](const auto &b, const auto &c) {
            return b + teleTime[c];
        }) > threshold);
    });

    // 输出结果
    if (candidateFriends.empty()){
        cout << "0" << endl;
    } else{
        map<string, unsigned long long > result;
        for (const auto &a:candidateFriends) {
            // 找最大的元素
            auto c = max_element(a.begin(), a.end(), [&](const auto &b, const auto &c) {
                return teleTime[b] < teleTime[c];
            });
            // 按照alphabet排序
            result[*c] = a.size();
        }
        cout << result.size() << endl;
        for (const auto & one: result) {
            cout << one.first << " " << one.second << endl;
        }
    }

    return 0;
}



#ifdef CASEID
#include "utils.h"

TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif