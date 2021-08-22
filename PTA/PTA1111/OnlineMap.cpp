//
// Created by ednow on 2021/8/21.
//

// modified from 1087

#define CASEID 1111  // 上交时注释


#ifdef CASEID
#define MAIN PTA1111
#else
#define MAIN main
#endif


#include "ios"
#include "iostream"
#include "vector"
#include "memory"
#include "string"
#include "map"
#include "algorithm"
#include "limits"
#include "numeric"

using namespace std;


// dijkstra求出来的一些信息
struct intersectionInfo{
    // 城市的唯一标识符
    int index{};
    // 累计路径长度
    int weight{INT32_MAX};
    // 存放父亲节点们的唯一标识符
    vector<int> parent{};
    explicit intersectionInfo(int index): index(index){}
};


void
get_path(vector<shared_ptr<intersectionInfo>> &nodes, vector<vector<int>> &paths, vector<int> &stack, int source, int destination){
    stack.push_back(source);
    if (source == destination){
        paths.emplace_back(stack.begin(), stack.end());
        stack.pop_back();
        return;
    }

    for (auto & parent:nodes[source]->parent) {
        get_path(nodes, paths, stack, parent, destination);
    }
    stack.pop_back();
}

void
dijkstra(vector<shared_ptr<intersectionInfo>> &nodes, vector<vector<int>> &graph){
    vector<shared_ptr<intersectionInfo>> unselectedNodes(nodes.begin(), nodes.end());
    while (!unselectedNodes.empty()){
        auto node = min_element(unselectedNodes.begin(), unselectedNodes.end(), [](const auto &a, const auto &b) {
            return a->weight < b->weight;
        });
        for (int i = 0; i < nodes.size(); ++i) {
            if (graph[(*node)->index][i]!=0){
                int newWeight = graph[(*node)->index][i] + (*node)->weight;
                if (newWeight < nodes[i]->weight){
                    nodes[i]->weight = newWeight;
                    nodes[i]->parent.clear();
                    nodes[i]->parent.push_back((*node)->index);
                    continue;
                }
                if (newWeight == nodes[i]->weight){
                    nodes[i]->parent.push_back((*node)->index);
                    continue;
                }
            }
        }
        unselectedNodes.erase(node);
    }
}

int
get_cost(vector<int> &path, int source, int destination, vector<vector<int>> &graph){
    int result{};
    auto iter1 = path.begin();
    auto iter2 = path.begin() + 1;
    while (iter2 != path.end()){
        result += graph[*iter1][*iter2];
        iter1++;
        iter2++;
    }
    return result;
}


int
MAIN(){
    // cityNum城市的数量
    // roadNum道路的数量
    // intersectionNum交点的数量
    // streetNum街道的数量
    int intersectionNum{}, streetNum{}, source{}, destination{};
    cin >> intersectionNum >> streetNum;
    // 图的零阶矩阵存储结构
    vector<vector<int>> lenGraph(intersectionNum, vector<int>(intersectionNum));
    vector<vector<int>> timeGraph(intersectionNum, vector<int>(intersectionNum));
    while (streetNum--){
        int a, b,t ,weight, time;
        cin >> a >> b >> t >> weight >> time;
        lenGraph[a][b] = weight;
        lenGraph[b][a] = weight;
        timeGraph[a][b] = time;
        timeGraph[b][a] = time;
    }

    cin >> source >> destination;

    // dijkstra
    vector<shared_ptr<intersectionInfo>> lenNodes(intersectionNum);
    for (int i = 0; i < intersectionNum; ++i) {
        lenNodes[i] = make_shared<intersectionInfo>(i);
    }
    // 反向dijkstra
    // 本来应该是sourceCity为源，为了方便求path，这里反向dijkstra
    lenNodes[destination]->weight = 0;
    dijkstra(lenNodes, lenGraph);
    vector<vector<int>> lenPaths;
    vector<int> lenStack;
    get_path(lenNodes, lenPaths, lenStack, source, destination);

    // dijkstra
    vector<shared_ptr<intersectionInfo>> timeNodes(intersectionNum);
    for (int i = 0; i < intersectionNum; ++i) {
        timeNodes[i] = make_shared<intersectionInfo>(i);
    }
    // 反向dijkstra
    // 本来应该是sourceCity为源，为了方便求path，这里反向dijkstra
    timeNodes[destination]->weight = 0;
    dijkstra(timeNodes, timeGraph);
    vector<vector<int>> timePaths;
    vector<int> timeStack;
    get_path(timeNodes, timePaths, timeStack, source, destination);

    auto lenResult = min_element(lenPaths.begin(), lenPaths.end(), [&](auto &a, auto &b) {
        int lenA = get_cost(a, source, destination, lenGraph);
        int lenB = get_cost(b, source, destination, lenGraph);
        if (lenA != lenB) return lenA < lenB;
        return get_cost(a, source, destination, timeGraph) < get_cost(b, source, destination, timeGraph);
    });

    auto timeResult = min_element(timePaths.begin(), timePaths.end(), [&](auto &a, auto &b) {
        int lenA = get_cost(a, source, destination, timeGraph);
        int lenB = get_cost(b, source, destination, timeGraph);
        if (lenA != lenB) return lenA < lenB;
        return a.size() < b.size();
    });

    if (*lenResult == *timeResult){
        cout << "Distance = " << get_cost(*lenResult, source, destination, lenGraph) 
        << "; Time = " << get_cost(*timeResult, source, destination, timeGraph) << ": ";
        auto pathIter = (*lenResult).begin();
        cout << *pathIter++;
        while (pathIter!=(*lenResult).end()){
            cout << " -> " << *pathIter;
            pathIter++;
        }
    }else{
        cout << "Distance = " << get_cost(*lenResult, source, destination, lenGraph) << ": ";
        auto pathIter = (*lenResult).begin();
        cout << *pathIter++;
        while (pathIter!=(*lenResult).end()){
            cout << " -> " << *pathIter;
            pathIter++;
        }
        cout << endl;

        cout << "Time = " << get_cost(*timeResult, source, destination, timeGraph) << ": ";
        pathIter = (*timeResult).begin();
        cout << *pathIter++;
        while (pathIter!=(*timeResult).end()){
            cout << " -> " << *pathIter;
            pathIter++;
        }
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


