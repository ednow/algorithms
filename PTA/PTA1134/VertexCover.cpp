//
// Created by ednow on 2021/8/27.
//
#define CASEID 1134

#ifdef CASEID
#define MAIN PTA1134
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int
MAIN(){
    int nodeNum{}, edgeNum{};
    cin >> nodeNum >> edgeNum;
    // 管理每个点的边
    vector<vector<int>> nodeToEdge(nodeNum);
    for (int i = 0; i < edgeNum; ++i)
    {
        int a, b;
        cin >> a >> b;
        nodeToEdge[a].push_back(i);
        nodeToEdge[b].push_back(i);
    }
    int queryNum;

    cin >> queryNum;
    while (queryNum--){
        int nodeSetSize;
        cin >> nodeSetSize;
        vector<bool> isEdgeDeleted(edgeNum, false);
        while (nodeSetSize--){
            int node;
            cin >> node;
            for (auto &edge: nodeToEdge[node]) {
                isEdgeDeleted[edge] = true;
            }
        }
        // 图中还有没删除的边
        if (find_if(isEdgeDeleted.begin(), isEdgeDeleted.end(), [](const auto &a){
            return a == false;
        })!=isEdgeDeleted.end()){
            cout << "No" << endl;
        } else{
            cout << "Yes" << endl;
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