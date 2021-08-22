//
// Created by ednow on 2021/8/22.
//

#define CASEID 1146

#ifdef CASEID
#define MAIN PTA1146
#else
#define MAIN main
#endif

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

struct result{
    int index{};
    // 是不是拓扑排序
    bool notTopologicalSort{false};
};

int
MAIN(){
    // nodeNum节点数量
    // edgeNum边的数量
    int nodeNum{}, edgeNum{};
    // 邻接表的存储方式
    // 反邻接表，是为了方便求入边
    cin >> nodeNum >> edgeNum;
    vector<vector<int>> Graph(nodeNum + 1);
    // 每个点的入边
    vector<int> inEdge(nodeNum + 1, 0);
    // 读边
    while (edgeNum--){
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        inEdge[b]++;
    }

    int queryNum{};
    cin >> queryNum;
    vector<result> results(queryNum);
    // 读query并处理,顺便初始化index
    for (int i = 0; i < queryNum; ++i) {
        vector<int> tempInEdge(inEdge.begin(), inEdge.end());
        for (int j = 1; j < nodeNum+1; ++j) {
            int node;
            cin >> node;
            // 如果出度为0可以被删除
            if (tempInEdge[node] == 0){
                for (auto &out: Graph[node]) {
                    tempInEdge[out]--;
                }
            }else{
                results[i].notTopologicalSort = true;
                // 把剩下的节点读完
                for (int k = j+1; k < nodeNum+1; ++k) {
                    cin >> node;
                }
                break;
            }
        }
        // 标记index
        results[i].index = i;
    }
    vector<result> answer;
    copy_if(results.begin(), results.end(), back_inserter(answer), [](const auto &a) {
        return a.notTopologicalSort;
    });
    auto iter = answer.begin();
    
    cout << (*iter).index;
    iter++;
    while (iter != answer.end()){
        cout << " " << (*iter).index;
        iter++;
    }
    cout << endl;
    return 0;
}


#ifdef CASEID
#include "utils.h"

TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif