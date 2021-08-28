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

using namespace std;

void
dfs(int source, vector<int> &isVisited, vector<vector<int>> &graph, vector<int> &path){
    bool isAllConnected = true;
    for (auto & a:path) {
        if (!graph[source][a]){
            isAllConnected = false;
            break;
        }
    }
    if (isAllConnected){
        path.push_back(source);
    }
    isVisited[source] = true;
    for (int i = 1; i < graph.size(); ++i) {
        if (graph[source][i] and !isVisited[i]){
            dfs(i, isVisited, graph, path);
        }
    }
}

int
MAIN(){
    int nodeNum{}, edgeNum{};
    cin >> nodeNum >> edgeNum;
    vector<vector<int>> graph(nodeNum + 1, vector<int>(nodeNum+1,0));
    while (edgeNum--){
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    vector<int> isVisited(nodeNum + 1);
    // 最大的子图们
    vector<unordered_set<int>> subGraph;
    vector<int> path;
    vector<int> isExactVisited(nodeNum + 1);
    for (int i = 1; i < nodeNum+1; ++i) {
        if (!isExactVisited[i]){
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