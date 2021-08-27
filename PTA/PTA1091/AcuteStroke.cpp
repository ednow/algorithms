//
// Created by ednow on 2021/8/27.
//
#define CASEID 1091

#ifdef CASEID
#define MAIN PTA1091
#else
#define MAIN main
#endif

#include "vector"
#include "iostream"
#include "algorithm"
#include "map"
#include "unordered_set"

using namespace std;

void
dfs(int source, map<int, unordered_set<int>> &graph, map<int, bool> &isVisited, vector<int> &path){
    isVisited[source] = true;
    path.push_back(source);
    for (const auto & neighbor: graph[source]) {
        if (!isVisited[neighbor]){
            dfs(neighbor, graph, isVisited, path);
        }
    }
}

int
MAIN(){
    int M, N, L, T;
    cin >> M >> N >> L >> T;
    // MRI扫描出来的三维切片
    vector<vector<vector<int>>> slices(L, vector<vector<int>>(M, vector<int>(N, 0)));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                cin >> slices[i][j][k];
            }
        }
    }

    map<int, unordered_set<int>> graph;
    unordered_set<int> isNotVisited;
    // 降维建图
    for (int z = 0; z < L; ++z) {
        for (int y = 0; y < M; ++y) {
            for (int x = 0; x < N; ++x) {
                // 是异常点
                if (slices[z][y][x]){
                    auto a = graph[z*N*M + y*N + x];// 在图中创建异常点
                    isNotVisited.insert(z*N*M + y*N + x);
                    if (x+1 < N){
                        if (slices[z][y][x+1]){
                            graph[z*N*M + y*N + x].insert(z*N*M + y*N + x + 1);
                            graph[z*N*M + y*N + x + 1].insert(z*N*M + y*N + x);
                        }
                    }

                    if (x-1>0){
                        if (slices[z][y][x-1]){
                            graph[z*N*M + y*N + x].insert(z*N*M + y*N + x-1);
                            graph[z*N*M + y*N + x-1].insert(z*N*M + y*N + x);
                        }
                    }

                    if (y+1 < M){
                        if (slices[z][y+1][x]){
                            graph[z*N*M + y*N + x].insert(z*N*M + (y+1)*N + x);
                            graph[z*N*M + (y+1)*N + x].insert(z*N*M + y*N + x);
                        }
                    }

                    if (y-1>0){
                        if (slices[z][y-1][x]){
                            graph[z*N*M + y*N + x].insert(z*N*M + (y-1)*N + x);
                            graph[z*N*M + (y-1)*N + x].insert(z*N*M + y*N + x);
                        }
                    }

                    if (z+1 < L){
                        if (slices[z+1][y][x]){
                            graph[z*N*M + y*N + x].insert((z+1)*N*M + y*N + x);
                            graph[(z+1)*N*M + y*N + x].insert(z*N*M + y*N + x);
                        }
                    }

                    if (z-1>0){
                        if (slices[z-1][y][x]){
                            graph[z*N*M + y*N + x].insert((z-1)*N*M + y*N + x);
                            graph[(z-1)*N*M + y*N + x].insert(z*N*M + y*N + x);
                        }
                    }
                }
            }
        }
    } // 降维建图

    // 区域的重量
    int weight{};
    // 某个节点有没有被访问过
    map<int, bool> isVisited;
    while (!isNotVisited.empty()){
        vector<int> path;
        dfs(*isNotVisited.begin(), graph, isVisited, path);

        if (path.size()>=T){
            weight += (int)path.size();
        }

        for (auto &a:path) {
            isNotVisited.erase(a);
        }
    }

    cout << weight;

    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif