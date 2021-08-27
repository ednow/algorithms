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
dfs(int z, int y, int x,
    int &M, int &N, int &L,
    vector<vector<vector<int>>> &slices, map<int, bool> &isVisited, vector<int> &path){
    isVisited[z*N*M + y*N + x] = true;
    path.push_back(z*N*M + y*N + x);
    if (x+1 < N){
        if (slices[z][y][x+1] and !isVisited[z*N*M + y*N + x + 1]){
            dfs(z, y, x + 1, M, N, L, slices, isVisited, path);
        }
    }

    if (x-1>=0){
        if (slices[z][y][x-1]and !isVisited[z*N*M + y*N + x - 1]){
            dfs(z, y, x - 1, M, N, L, slices, isVisited, path);
        }
    }

    if (y+1 < M){
        if (slices[z][y+1][x] and !isVisited[z*N*M + (y+1)*N + x]){
            dfs(z, y+1, x, M, N, L, slices, isVisited, path);
        }
    }

    if (y-1>=0){
        if (slices[z][y-1][x] and !isVisited[z*N*M + (y-1)*N + x]){
            dfs(z, y-1, x, M, N, L, slices, isVisited, path);
        }
    }

    if (z+1 < L){
        if (slices[z+1][y][x] and !isVisited[(z+1)*N*M + y*N + x]){
            dfs(z+1, y, x, M, N, L, slices, isVisited, path);
        }
    }

    if (z-1>=0){
        if (slices[z-1][y][x] and !isVisited[(z-1)*N*M + y*N + x]){
            dfs(z-1, y, x, M, N, L, slices, isVisited, path);
        }
    }
}

int
MAIN(){
    int M, N, L, T;
    cin >> M >> N >> L >> T;
    // MRI扫描出来的三维切片
    vector<vector<vector<int>>> slices(L, vector<vector<int>>(M, vector<int>(N, 0)));
    unordered_set<int> isNotVisited;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                cin >> slices[i][j][k];
                if (slices[i][j][k] == 1){
                    isNotVisited.insert(i*N*M + j*N + k);
                }

            }
        }
    }

    // 区域的重量
    int weight{};
    // 某个节点有没有被访问过
    map<int, bool> isVisited;
    while (!isNotVisited.empty()){
        vector<int> path;
        auto label = *isNotVisited.begin();
        int z = label / (N * M);
        int y = (label - z*N*M) / N;
        int x = label % N;
        dfs(z, y, x, M, N, L, slices, isVisited, path);

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