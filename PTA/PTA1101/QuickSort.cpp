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
#include "algorithm"


using namespace std;

int
MAIN(){
    int N;
    cin >> N;
    if (N==0) {
        cout << 0;
        return 0;
    }

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    // 存放[0,i]之间最大的数
    vector<int> maxZeroToI(N);
    maxZeroToI[0] = nums[0];
    // 第一次dp,求最大的数
    for (int i = 1; i < N; ++i) {
        if (maxZeroToI[i-1] < nums[i]) {
            maxZeroToI[i] = nums[i];
        } else {
            maxZeroToI[i] = maxZeroToI[i-1];
        }
    }

    // 存放[i,N]之间最小的数
    vector<int> minIToN(N);
    minIToN[N-1] = nums[N-1];
    for (int i = N-2; i >= 0; --i) {
        if (minIToN[i+1] > nums[i]) {
            minIToN[i] = nums[i];
        } else {
            minIToN[i] = minIToN[i+1];
        }
    }
    // 顺次找到最小值和最大值

    // 判断k是不是做过枢纽
    // dp[0][k-1].second < nums[k],(左边的最大值也小于k位置的数)
    // dp[k+1][N].first > nums[k],(右边的最小值也大于k位置的数)
    vector<int> result;
    result.reserve(N);
    for (int i = 1; i < N-1; ++i) {
        if (maxZeroToI[i - 1] < nums[i] and minIToN[i + 1] > nums[i]) {
            result.push_back(nums[i]);
        }
    }
    // 边界单独判断
    if (minIToN[1]>nums[0]) {
        result.push_back(nums[0]);
    }

    if (maxZeroToI[N-2] < nums[N-1]) {
        result.push_back(nums[N - 1]);
    }
    // 测试点2
    if (result.empty()) {
        cout << 0 << endl << endl;
        return 0;
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    auto iter = result.begin();
    cout << *iter++;
    while (iter != result.end()) {
        cout << " " << *iter++;
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