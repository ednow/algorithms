//
// Created by ednow on 2021/8/22.
//

#define CASEID 1013

#ifdef CASEID
#define MAIN PTA1013
#else
#define MAIN main
#endif

#include "vector"
#include "iostream"
#include "set"
//#include "unordered_set"
#include "algorithm"

//#define set unordered_set

using namespace std;

//typedef unordered_set set;

void dfs(int start, vector<vector<bool>> &graph, vector<bool> &isVisited, vector<int> &nodesToDeleted){
    isVisited[start] = true;
    nodesToDeleted.push_back(start);
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[start][i] and !isVisited[i]){
            dfs(i, graph, isVisited, nodesToDeleted);
        }
    }
};

int
occupy_city(int node, vector<vector<bool>> graph, int nodeNum){
    // 进行dfs的次数
    auto dfsTimes = -1;
    for (int i = 0; i < graph.size(); ++i) {
        graph[i][node] = false;
        graph[node][i] = false;
    }
    set<int> nodes;
    for (int i = 1; i < nodeNum+1; ++i) {
        nodes.insert(i);
    }
    nodes.erase(node);
    vector<bool> isVisited(nodeNum+1, false);
    isVisited[node] = true;
    isVisited[0] = true;
    while (!nodes.empty()){
        vector<int> nodesToDeleted;
        dfs(*nodes.begin(), graph, isVisited, nodesToDeleted);
        for (int & iter : nodesToDeleted){
            nodes.erase(iter);
        }
        dfsTimes++;
    }

    return dfsTimes;
}

int MAIN(){
    int nodeNum{}, edgeNum{}, queryNum{};
    cin >> nodeNum >> edgeNum >> queryNum;
    vector<vector<bool>> graph(nodeNum + 1, vector<bool>(nodeNum + 1, false));
    while (edgeNum--){
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    vector<int> repairNums;
    repairNums.reserve(queryNum);
    while (queryNum--){
        int node;
        cin >> node;
        repairNums.push_back(occupy_city(node, graph, nodeNum));
    }

    // 输出结果
    for (int & repairNum : repairNums) {
        cout << repairNum << endl;
    }

    return 0;
};

#ifdef CASEID
#include "utils.h"

TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif