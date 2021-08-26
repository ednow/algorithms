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
#include "limits"
#include "queue"
#include "numeric"
#include "iomanip"

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


// 存储bfs得到的信息
struct Station{
    // 最近距离的父亲们
    // 不能用vector,比如3212中
    unordered_set<int> fathers;
    // 距离源点的长度
    int len{INT32_MAX};
};

// queue中存放的信息
struct item{
    // station的编号
    int label;
    // 距离源点的距离
    int distance;

};

//
void
dfs(
    // 源
    int source,
    // 目标
    int destination,
    map<int, vector<int>> &graph,
    // 当前遍历到的节点
    vector<int> &stack,
    // 存放有效路径
    vector<vector<int>> &result,
    // 某个节点有没有被访问
    map<int, bool> &isVisited,
    // 存储bfs得到的信息
    map<int, Station> &bfsInfo
) {
    stack.push_back(source);
    isVisited[source] = true;
    if (source == destination){
        result.emplace_back(stack.begin(), stack.end());
        stack.pop_back();
        return;
    }

    for (const auto &next: bfsInfo[source].fathers) {
        dfs(next, destination, graph, stack, result, isVisited, bfsInfo);
    }

    stack.pop_back();
}

// 找到节点之间最短路径的关系
// 应该是只能用bfs搜索,受dijkstra算法的启发
void
bfs(
    // 源点
    int source,
    // 图
    map<int, vector<int>> &graph,
    // 存储bfs得到的信息
    map<int, Station> &bfsInfo,
    // 节点是否被访问过
    map<int, bool> &isVisited
)
{

    queue<item> q;
    q.push(item{.label=source, .distance=0});
    isVisited[source] = true;

    while (!q.empty()){
        auto head = q.front();
        auto distance = head.distance;
        auto label = head.label;
        isVisited[label] = true;
        for (const auto &child: graph[label]) {
            // 孩子没有被访问过就压入到队列中
            if (!isVisited[child]){
                q.push(item{.label=child, .distance=distance + 1});
            }

            // 找到更短的距离
            if (bfsInfo[child].len > distance + 1){
                bfsInfo[child].len = distance + 1;
                bfsInfo[child].fathers.clear();
                bfsInfo[child].fathers.insert(label);
                continue;
            }

            // 距离相等
            if (bfsInfo[child].len == distance + 1){
                bfsInfo[child].fathers.insert(label);
            }

        }
        q.pop();
    }


}

int
MAIN(){
    // 路线的数量
    int lineNum;
    cin >> lineNum;
    // 维护每一条地铁线路
    vector<vector<int>> lines(lineNum+1);
    map<int, unordered_set<int>> stationToLine;
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

    // 给路径染色
    map<int, map<int, int>> pathToLine;
    // 维护图中两个站是否存在路线
    // 邻接表
    map<int, vector<int>> graph;
    for (int i = 1; i < lines.size(); ++i) {
        for (int j = 0; j <= lines[i].size() - 2; ++j) {
            graph[lines[i][j]].push_back(lines[i][j + 1]);
            graph[lines[i][j + 1]].push_back(lines[i][j]);
            // 给路径染色
            pathToLine[lines[i][j]][lines[i][j + 1]] = i;
            pathToLine[lines[i][j + 1]][lines[i][j]] = i;
        }
    }

//    记录某个站是不是转乘站
    map<int, bool> isTransfer;
    for (auto & a:stationToLine) {
        if (a.second.size() > 1){
            isTransfer[a.first] = true;
        } else{
            isTransfer[a.first] = false;
        }
    }

    int queryNum;
    cin >> queryNum;
    while (queryNum--){
        int a, b;
        cin >> a >> b;
        vector<vector<int>> result;
        vector<int> stack;
        // 储存bfs得到的一些信息, station label -> info
        map<int, Station> bfsInfo;
        // 该节点是否被访问过
        map<int, bool> isVisited;
        // 反向的时候要设置的是b的len为0
        bfsInfo[b].len = 0;
        // 反向最短路径
        bfs(b, graph, bfsInfo, isVisited);
        isVisited.clear();
        dfs(a, b, graph, stack, result, isVisited, bfsInfo);
        auto answer = min_element(result.begin(), result.end(), [&](const auto &a, const auto &b) {
            if (a.size() != b.size()) return a.size() < b.size();
            return accumulate(a.begin(), a.end(), 0, [&](auto &c, auto &d) {
                return c + isTransfer[d];
            }) < accumulate(b.begin(), b.end(), 0, [&](auto &c, auto &d) {
                return c + isTransfer[d];
            });});
        auto step = (*answer).begin();
        // 开始的地铁线路
        int prevLine = pathToLine[*step][*(step+1)];
        // 开始站
        int startStation = *step;
        step++;
        // 路线
        vector<path> paths;

        // 没有走到尽头
        // 最后一个让后面来收尾，防止一路走到底的刚好换站记录错的bug
        while (step != (*answer).end() - 1){
            // 现在走到的地铁线路
            int lineByNow = pathToLine[*step][*(step+1)];
            // 线路不一致，而且不是transfer station
            // 产生换线
            if (prevLine != lineByNow){
                paths.push_back(path{.line=prevLine, .start=startStation, .end=*step});
                startStation = *step;
                prevLine = lineByNow;
            }
            step++;
        }

        paths.push_back(path{.line=prevLine, .start=startStation, .end=*step});

        cout << (*answer).size() - 1 << endl;
        for (const auto &p: paths) {
            cout << "Take Line#" << p.line << " from ";
            cout << setw(4) << setfill('0') <<  p.start << " to " << setw(4) << setfill('0') << p.end << "." << endl;
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