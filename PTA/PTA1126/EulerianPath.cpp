//
// Created by ednow on 2021/8/28.
//

#define CASEID 1126

#ifdef CASEID
#define MAIN PTA1126
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "numeric"

using namespace std;

void
dfs(int source, vector<vector<int>> &graph, vector<int> &isVisited){
    isVisited[source] = true;
    for (int i = 1; i < graph.size(); ++i)
    {
        if (graph[source][i] and !isVisited[i]){
            dfs(i, graph, isVisited);
        }
    }
}


int
MAIN(){
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;
    vector<int> degrees(nodeNum + 1, 0);
    vector<vector<int>> graph(nodeNum+1, vector<int>(nodeNum+1,0));
    vector<int> isVisited(nodeNum+1,0);
    while (edgeNum--){
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
        degrees[a]++;
        degrees[b]++;
    }
    int dfsTimes{};
    for (int i = 1; i < nodeNum+1; ++i) {
        if (!isVisited[i]){
            dfs(i, graph, isVisited);
            dfsTimes++;
        }
    }

    vector<int> isNotEven;
    isNotEven.reserve(nodeNum + 1);
    for (auto &a: degrees) {
        isNotEven.push_back(a % 2);
    }
    int notEvenNum = accumulate(isNotEven.begin(), isNotEven.end(), 0, plus<>());
    auto a = degrees.begin()+1;
    for (; a != degrees.end() - 1; ++a) {
        cout << *a << " ";
    }
    cout << *a << endl;
    if (dfsTimes>1){
        cout << "Non-Eulerian";
        return 0;
    }
    switch (notEvenNum) {
        case 0:
            cout << "Eulerian";
            break;
        case 2:
            cout << "Semi-Eulerian";
            break;
        default:
            cout << "Non-Eulerian";
            break;
    }

    return 0;
};


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif