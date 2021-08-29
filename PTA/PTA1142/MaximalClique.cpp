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
bfs(int source, vector<int> &isVisited, vector<unordered_set<int>> &graph, unordered_set<int> &path){
    // 周围邻居的公共顶点
    unordered_set<int> common(graph[source].begin(), graph[source].end());
    common.insert(source);
    queue<int> q;
    q.push(source);
    while (!q.empty()){
        auto head = q.front();
        isVisited[head] = true;
        unordered_set<int> tempCommon;
        // 对节点周围的节点的孩子和原集合做交集
        for (auto & neighbor: graph[head]) {
            if (!isVisited[neighbor]){
                set_intersection(common.begin(), common.end(), graph[neighbor].begin(), graph[neighbor].end(),
                                 inserter(tempCommon, tempCommon.end()));
                common.insert(tempCommon.begin(), tempCommon.end());
                tempCommon.clear();
            }
        }
        // 下一轮的搜索
        for (auto & next:common) {
            if (!isVisited[next]){
                q.push(next);
            }
        }
        q.pop();
    }
    path = common;
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
            bfs(i, isVisited, graph, path);
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