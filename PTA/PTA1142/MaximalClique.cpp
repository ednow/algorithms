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

// other是为了捕获2-3这种clique
void
get_clique(int source, vector<int> &isVisited, vector<unordered_set<int>> &graph, unordered_set<int> &path, vector<int> &other){
    if (graph[source].empty()){
        path.insert(source);
        return;
    }
    // 周围邻居的公共顶点
    path.insert(graph[source].begin(), graph[source].end());
    path.insert(source);
    for (auto & neighbor: graph[source]) {

        // clique之间是全连接的，出现原来不存在的代表不是这个clique里面
        for (auto & nextNeighbor: graph[neighbor]) {
            if (path.find(nextNeighbor) == path.end()){
                path.erase(neighbor);

                if (!isVisited[neighbor]){  // 防止案例中先访问2,再访问3,会多出来一个2,3
                    other.push_back(neighbor);
                }

                break;
            }
        }
    }
    // 防止星型结构，如果source被纳入other求出来clique，会将形成source单独称为max clique的bug
    // 只有孤立点会出现path.size == 1
    if (path.size()==1){
        path.erase(source);
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
    vector<int> other;
    for (int i = 1; i < nodeNum+1; ++i) {
        if (!isVisited[i]){
            get_clique(i, isVisited, graph, path, other);
            subGraph.emplace_back(path.begin(), path.end());
            for (auto &a: path) {
                isVisited[a] = true;
            }
            // other和i将构成max clique
            for (auto &a: other) {
                subGraph.emplace_back(unordered_set<int>({i, a}));
            }

            path.clear();
            other.clear();
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