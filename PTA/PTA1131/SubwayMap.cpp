//
// Created by ednow on 2021/8/24.
//


#define CASEID 1131

#ifdef CASEID
#define MAIN PTA1131
#else
#define MAIN main
#endif

#include "string"
#include "vector"
#include "iostream"
#include "map"
#include "algorithm"
#include "unordered_set"

using namespace std;

#define MAX_SUBWAY_STATION_NUM 10000

// 保存答案的路径
struct path{
    // 几号线
    int line{};
    // 路线的开始
    int start{};
    // 路线的终点站
    int end{};
    // 路线的长度
//    int len{};
};

void
dfs(
    // 源
    int source,
    // 目标
    int destination,
    vector<vector<bool>> &graph,
    // 当前遍历到的节点
    vector<int> &stack,
    // 存放有效路径
    vector<vector<int>> &result,
    // 某个节点有没有被访问
    vector<bool> &isVisited
) {
    stack.push_back(source);
    isVisited[source] = true;
    if (source == destination){
        result.emplace_back(stack.begin(), stack.end());
        stack.pop_back();
        return;
    }

    for (int i = 0; i < MAX_SUBWAY_STATION_NUM; ++i) {
        if (graph[source][i] and !isVisited[i]){
            dfs(i, destination, graph, stack, result, isVisited);
        }else{
            if (i == destination){
                stack.push_back(i);
                result.emplace_back(stack.begin(), stack.end());
                stack.pop_back();
            }
        }
    }

    stack.pop_back();
}


int
MAIN(){
    // 路线的数量
    int lineNum;
    cin >> lineNum;
    // 维护每一条地铁线路
    vector<vector<int>> lines(lineNum+1);
    vector<unordered_set<int>> stationToLine(MAX_SUBWAY_STATION_NUM);
    for (int i = 1; i < lineNum + 1; ++i) {
        int stationNum;
        cin >> stationNum;
        while (stationNum--){
            int station;
            cin >> station;
            lines[i].push_back(station);
            stationToLine[station].insert(i);
        }
    }

    // 维护图中两个站是否存在路线
    vector<vector<bool>> graph(MAX_SUBWAY_STATION_NUM, vector<bool>(MAX_SUBWAY_STATION_NUM));
    for (int i = 1; i < lines.size(); ++i) {
        for (int j = 0; j < lines[i].size() - 2; ++j) {
            graph[lines[i][j]][lines[i][j + 1]] = true;
            graph[lines[i][j + 1]][lines[i][j]] = true;
        }
    }

    int queryNum;
    cin >> queryNum;
    while (queryNum--){
        int a, b;
        cin >> a >> b;
        vector<vector<int>> result;
        vector<int> stack;
        vector<bool> isVisited(MAX_SUBWAY_STATION_NUM, false);
        dfs(a, b, graph, stack, result, isVisited);
        auto answer = min_element(result.begin(), result.end(), [](const auto &a, const auto &b) {
            return a.size() < b.size();
        });
        auto step = (*answer).begin();
        // 开始的地铁线路
        int prevLine = *stationToLine[*step].begin();
        // 开始站
        int startStation = *step;
        step++;
        // 现在走到的地铁线路
        int lineByNow = *stationToLine[*step].begin();
        // 现在走到的地铁站
        int stationByNow = *step;

        // 路线
        vector<path> paths;

        // 没有走到尽头
        // 最后一个让后面来收尾，防止一路走到底的刚好换站记录错的bug
        while (step != (*answer).end()){
            // 线路不一致，而且不是transfer station
            // 产生换线
            if (prevLine != lineByNow and stationToLine[*step].size() == 1){
                paths.push_back(path{.line=prevLine, .start=startStation, .end=*(step - 1)});
                startStation = stationByNow;
                prevLine = lineByNow;
            }
            step++;
            stationByNow = *step;
            lineByNow = *stationToLine[*step].begin();
        }

        paths.push_back(path{.line=prevLine, .start=startStation, .end=*step});

        cout << (*answer).size() << endl;
        for (const auto &p: paths) {
            cout << "Take Line#" << p.line << " from " << p.start << " to " << p.end << endl;
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