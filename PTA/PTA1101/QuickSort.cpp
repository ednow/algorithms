//
// Created by ednow on 2021/9/2.
//

#define CASEID 1101

#ifdef CASEID
#define MAIN PTA1101
#else
#define MAIN main
#endif

#include "vector"
#include "map"
#include "iostream"

using namespace std;

int
MAIN(){
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    // 存放[i,j]内的最小和最大值
    // first为最小值,second为最大值
    vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(N));

    // 顺次找到最小值和最大值

    // 判断k是不是做过枢纽
    // dp[0][k-1].second > nums[k],(左边的最大值也小于k位置的数)
    // dp[k+1][N].first < nums[k],(右边的最小值也大于k位置的数)
    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif