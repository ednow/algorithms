//
// Created by ednow on 2021/8/28.
//
#define CASEID 1142

#ifdef CASEID
#define MAIN PTA1142
#else
#define MAIN main
#endif

#include "vector"
#include "unordered_set"
#include "iostream"
#include "queue"
#include "algorithm"

using namespace std;

void
dfs(int source, vector<int> &isVisited, vector<unordered_set<int>> &graph, unordered_set<int> &path){
    isVisited[source] = true;
    // 周围邻居的公共顶点
    unordered_set<int> common;
    for (auto &neighbor: graph[source]) {
        unordered_set<int> res;
        set_intersection(graph[neighbor].begin(), graph[neighbor].end(), common.begin(), common.end(),
                         inserter(res, res.end()));

    }
}

int
MAIN(){
    int nodeNum{}, edgeNum{};
    cin >> nodeNum >> edgeNum;
    vector<unordered_set<int>> graph(nodeNum + 1);
    while (edgeNum--){
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector<int> isVisited(nodeNum + 1);
    // 最大的子图们
    vector<unordered_set<int>> subGraph;
    unordered_set<int> path;
    vector<int> isExactVisited(nodeNum + 1);
    for (int i = 1; i < nodeNum+1; ++i) {
        if (!isExactVisited[i]){
            path.insert(i);
            dfs(i, isVisited, graph, path);
            subGraph.emplace_back(path.begin(), path.end());
            for (auto &a: path) {
                isExactVisited[a] = true;
            }
            isVisited = isExactVisited;
            path.clear();
        }
    }
    int queryNum;
    cin >> queryNum;
    while (queryNum--) {
        int setNodeNum{};
        bool isClique{true};
        cin >> setNodeNum;
        int a;
        cin >> a;
        int clusterNum{};
        for (int i = 0; i < subGraph.size(); ++i) {
            if (subGraph[i].find(a) != subGraph[i].end()){
                clusterNum = i;
            }
        }

        for (int i = 1; i < setNodeNum; ++i) {
            cin >> a;
            if (subGraph[clusterNum].find(a) == subGraph[clusterNum].end()){
                isClique = false;
                break;
            }
        }

        if (isClique){
            if (setNodeNum == subGraph[clusterNum].size()){
                cout << "Yes" << endl;
            } else{
                cout << "Not Maximal" << endl;
            }
        } else{
            cout << "Not a Clique" << endl;
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