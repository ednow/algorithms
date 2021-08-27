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
#include "queue"

using namespace std;

struct item{
    int x{};
    int y{};
    int z{};
};

int
bfs(int z, int y, int x,
    int &M, int &N, int &L,
    vector<vector<vector<int>>> &slices, vector<vector<vector<int>>> &isVisited, int T){
    isVisited[z][y][x] = true;
    queue<item> q;
    q.push(item{.x=x, .y=y, .z=z});
    int w = 0;
    while (!q.empty()){
        auto head = q.front();
        x = head.x;
        y = head.y;
        z = head.z;

        w++;
        if (x+1 < N){
            if (slices[z][y][x+1] and !isVisited[z][y][x+1]){
                isVisited[z][y][x+1] = true;
                q.push(item{.x=x + 1, .y=y, .z=z});
            }
        }

        if (x-1>=0){
            if (slices[z][y][x-1]and !isVisited[z][y][x-1]){
                isVisited[z][y][x-1] = true;
                q.push(item{.x=x - 1, .y=y, .z=z});
            }
        }

        if (y+1 < M){
            if (slices[z][y+1][x] and !isVisited[z][y+1][x]){
                isVisited[z][y+1][x] = true;
                q.push(item{.x=x, .y=y+1, .z=z});
            }
        }

        if (y-1>=0){
            if (slices[z][y-1][x] and !isVisited[z][y-1][x]){
                isVisited[z][y-1][x] = true;
                q.push(item{.x=x, .y=y-1, .z=z});
            }
        }

        if (z+1 < L){
            if (slices[z+1][y][x] and !isVisited[z+1][y][x]){
                isVisited[z+1][y][x] = true;
                q.push(item{.x=x, .y=y, .z=z+1});
            }
        }

        if (z-1>=0){
            if (slices[z-1][y][x] and !isVisited[z-1][y][x]){
                isVisited[z-1][y][x] = true;
                q.push(item{.x=x, .y=y, .z=z-1});
            }
        }

        q.pop();
    }
    if (w>=T){
        return w;
    }else{
        return 0;
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
    vector<vector<vector<int>>> isVisited(L, vector<vector<int>>(M, vector<int>(N, 0)));
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                if (slices[i][j][k] and !isVisited[i][j][k]){
                    weight+=bfs(i, j, k, M, N, L, slices, isVisited, T);
                }
            }
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