//
// Created by ednow on 2021/8/27.
//
#define CASEID 1150

#ifdef CASEID
#define MAIN PTA1150
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

int
MAIN(){
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;

    vector<vector<int>> graph(nodeNum+1,vector<int>(nodeNum+1));
    while (edgeNum--){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = w;
        graph[b][a] = w;
    }

    int queryNum;
    cin >> queryNum;
    vector<int> visitedTimes(nodeNum + 1);
    // 保存最终答案的候选
    // dist -> queryId
    map<int, int> tsCycle;
    for (int queryId = 1; queryId < queryNum+1; ++queryId) {
        // 本次旅行长度
        int dist{};
        bool isQueryNotEdge(false);
        vector<int> path;
        visitedTimes.assign(nodeNum + 1, 0);
        visitedTimes[0] = 1;
        // 点集长度
        int pathNodeNum{};
        cin >> pathNodeNum;
        // 走一遍请求给定的路径
        int a;
        cin >> a;
        path.push_back(a);
        pathNodeNum--;
        while (pathNodeNum--){
            int b;
            cin >> b;
            if (graph[a][b] > 0){
                dist += graph[a][b];
                visitedTimes[a]++;
                visitedTimes[b]++;
                path.push_back(b);
                a = b;
            } else{
                isQueryNotEdge = true;
            }
        }

        // 访问了不存在的边
        if (isQueryNotEdge){
            cout << "Path " << queryId << ": NA (Not a TS cycle)" << endl;
            continue;
        }

        // 存在没有被访问的点
        if (find_if(visitedTimes.begin(), visitedTimes.end(), [](const auto &b){
            return b == 0;
        }) != visitedTimes.end()){
            cout << "Path "<< queryId <<": " << dist <<" (Not a TS cycle)" << endl;
            continue;
        }

        // 没有回到最初的起点
        if (*(path.begin()) != *(path.end()-1)){
            cout << "Path "<< queryId <<": " << dist <<" (Not a TS cycle)" << endl;
            continue;
        }

        tsCycle[dist] = queryId;
        // 点是否访问了不超过一次
        // 实际上在本算法中会记录两次
        if (find_if(visitedTimes.begin(), visitedTimes.end(), [](const auto &b){
            return b > 2;
        }) == visitedTimes.end()){
            cout << "Path "<< queryId <<": " << dist <<" (TS simple cycle)" << endl;
        }else{
            cout << "Path "<< queryId <<": " << dist <<" (TS cycle)" << endl;
        }
    }
    cout << "Shortest Dist("<< (*tsCycle.begin()).second << ") = "<< (*tsCycle.begin()).first;


    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif