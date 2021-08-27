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
#include "cmath"

using namespace std;

struct position{
    // 第二维度，位于一个slice平面
    int x{};
    // slices平面第三维度
    int y{};
    // slices第一维度
    int z{};
};

void
dfs(int level, const vector<vector<vector<int>>> &slices, vector<vector<vector<int>>> &color){

}


int
MAIN(){
    int M, N, L, T;
    cin >> M >> N >> L >> T;
    // MRI扫描出来的三维切片
    vector<vector<vector<int>>> slices(L, vector<vector<int>>(M, vector<int>(N, 0)));
    // 染色法求邻接的区域
    vector<vector<vector<int>>> color(slices.begin(), slices.end());


    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif