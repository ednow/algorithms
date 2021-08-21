//
// Created by ednow on 2021/8/20.
//

#define CASEID 1072  // 上交时把这一行注释掉

#ifdef CASEID
#define MAIN PTA1072
#else
#define MAIN main
#endif

#include "iostream"
#include "ios"
#include "string"
#include "vector"
#include "cstdio"
#include "memory"
#include "map"
#include "algorithm"
#include "limits"
#include "numeric"
#include "iomanip"


using namespace std;

struct Node{
    // 节点的编号
    // 编号在前的节点时station，house的节点index为本身的index+stationNum
    int index{};
    // 节点的权值
    int weight{INT32_MAX};
    // 本不需要记录父亲这些相关信息
    explicit Node(int index): index(index) {};

};

struct stationInfo{
    // 最小的距离
    int miniWeight{};
    // 最小距离的权值和
    int sumOfWeight{};
    // 能不能建，（必须覆盖到所有的house）
    bool isOk{false};
    int index{};
};

int
MAIN (){
    // stationNum加油站的数量
    int stationNum{}, houseNum{}, roadNum{}, maxDistance{};
    cin >>houseNum  >> stationNum >> roadNum >> maxDistance;
    // 邻接矩阵表示法
    // 编号在前的节点时station，house的节点index为本身的index+stationNum
    vector<vector<int>> graph(stationNum + houseNum + 1, vector<int>(stationNum + houseNum + 1,0));
    // 每个加油站的评估信息表
    // index=0代表加油站1
    vector<stationInfo> stations(stationNum+1);
    for (int i = 0; i < stationNum+1; ++i) {
        stations[i].index = i;
    }

    while (roadNum--){
        // 临时的节点标识符
        string a, b;
        // 真正在图中的index
        int ai{}, bi{};
        // 临时的边权重
        int weight{};
        cin >> a >> b >> weight;
        // 转换成真正的ai
        if (a.at(0) == 'G'){
            sscanf(a.c_str(), "G%d", &ai);
        }else{
            sscanf(a.c_str(), "%d", &ai);
            ai += stationNum;
        }
        
        // 转换成真正的bi
        if (b.at(0) == 'G'){
            sscanf(b.c_str(), "G%d", &bi);
        }else{
            sscanf(b.c_str(), "%d", &bi);
            bi += stationNum;
        }

        graph[ai][bi] = weight;
        graph[bi][ai] = weight;
    }

    // 对每个station求一次dijkstra
    for (int i = 1; i < stationNum + 1; ++i) {
        // 记录所有节点的状态
        vector<Node *> nodes(stationNum + houseNum + 1);
        for (int j = 0; j < stationNum + houseNum + 1; ++j) {
            nodes[j] = new Node(j);
        }
        // 记录未选点集
        vector<Node *> unSelectedNodes(nodes.begin(), nodes.end());
        // 源的路径长度设置为0
        nodes[i]->weight = 0;
        while (!unSelectedNodes.empty()){
            // 权值最小的节点
            auto node = min_element(nodes.begin(), nodes.end(), [](const auto &a, const auto &b) {
                return a->weight < b->weight;
            });
            // 更新距离列表信息
            for (int j = 1; j < stationNum + houseNum + 1; ++j) {
                int edge = graph[(*node)->index][j];
                if (edge != 0){
                    if ((*node)->weight + edge < nodes[j]->weight){
                        nodes[j]->weight = (*node)->weight + edge;
                    }
                }
            }
            // 加入已选集合
            unSelectedNodes.erase(node);
        }

        // 如果到房子的距离大于maxDistance，那么该修建地址不合理
        if (find_if(nodes.begin() + 1, nodes.end(), [&](const auto & a){ return a -> weight > maxDistance; }) != nodes.end()) {
            stations[i].isOk = false;
            continue;
        }

        // 将能够通向所有村庄设置为true
        stations[i].isOk = true;

        // 记录这个最短路径的离村庄的最小距离
        stations[i].miniWeight = (*min_element(nodes.begin(), nodes.end(), [](const auto &a, const auto &b) {
            return a->weight < b->weight;})) -> weight;

        // 求所有节点的权重和
        stations[i].sumOfWeight = accumulate(nodes.begin() + 1, nodes.end(), 0,
                                             [](const auto &a, const auto &b) { return a + b->weight; });
    }

    // 筛选出能通往所有村庄的加油站
    vector<stationInfo> candidateStation;
    copy_if(stations.begin(), stations.end(), back_inserter(candidateStation), [](const auto & a){
        return a.isOk == true;
    });
    if (candidateStation.empty()){
        cout << "No Solution" << endl;
    }

    auto result = min_element(candidateStation.begin(), candidateStation.end(), [](const auto &a, const auto &b){
        if (a.miniWeight != b.miniWeight) return a.miniWeight > b.miniWeight;
        if (a.sumOfWeight != b.sumOfWeight) return a.sumOfWeight < b.sumOfWeight;
        return a.index < b.index;
    });
    cout << "G" << (*result).index << endl;
    cout << setprecision(1) << fixed << (*result).miniWeight << " " << (*result).sumOfWeight / houseNum;
    return 0;
}

#ifdef CASEID
#include "utils.h"

TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif