//
// Created by ednow on 2021/8/27.
//
#define CASEID 1076

#ifdef CASEID
#define MAIN PTA1076
#else
#define MAIN main
#endif

#include "vector"
#include "iostream"
#include "queue"


using namespace std;

struct item{
    int level{};
    int idx{};
};

void bfs(int source, vector<vector<int>> &graph, vector<bool> &isVisited, int &forwardTimes, int maxLevel){
    queue<item> q;
    q.push(item{.level=1, .idx=source});
    isVisited[source] = true;
    while (!q.empty()){
        auto head = q.front();
        for (const auto &child: graph[head.idx]) {
            if (!isVisited[child]){
                isVisited[child] = true;
                if (head.level <= maxLevel){
                    forwardTimes++;
                }
                if (head.level < maxLevel){
                    q.push(item{.level=head.level+1, .idx=child});
                }
            }

        }
        q.pop();
    }
}

int MAIN(){

    int nodeNum, maxLevel;
    cin >> nodeNum >> maxLevel;
    // 记录每个节点的出度
    vector<vector<int>> graph(nodeNum+1);
    for (int i = 1; i < nodeNum+1; ++i) {
        int inNum;
        cin >> inNum;
        while (inNum--){
            int a;
            cin >> a;
            graph[a].push_back(i);
        }
    }

    int queryNum;
    cin >> queryNum;
    while (queryNum--){
        int source;
        cin >> source;
        vector<bool> isVisited(nodeNum+1, false);
        int forwardTimes{0};

        bfs(source, graph, isVisited, forwardTimes, maxLevel);
        cout << forwardTimes << endl;
    }

    return 0;
}


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif