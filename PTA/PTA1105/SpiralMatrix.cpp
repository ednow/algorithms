//
// Created by ednow on 2021/9/8.
//

#define CASEID 1105

#ifdef CASEID
#define MAIN PTA1105
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"

using namespace std;

int
MAIN(){

    // 读取数据
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    if (N == 1) {
        cout << nums[0] << endl;
        return 0;
    }
    // 排序
    sort(nums.begin(), nums.end(), [](const auto &a, const auto &b) {
        return a > b;
    });


    // m为列数,n为行数
    int m{},n{};
    for (int i = 1; i <= sqrt(N); ++i) {
        if (N % i == 0) {
            m = i;
        }
    }
    n = N / m;

    if (n > m) {
        swap(n, m);
    }

    vector<vector<int>> matrix(m,vector<int>(n));

    // finish,填充的字符个数
    // maxI,上下移动的最多次数
    // maxJ,左右移动的最多次数
    // startI,开始行号
    // startJ,结束行号
    int finish{}, maxI{m-1}, maxJ{n-1},startI{0}, startJ{0};

    while (finish < N-1) {
        matrix[startI][startJ] = nums[finish];

        // 向右移动
        for (int i = 0; i < maxJ and finish < N-1; ++i) {
            matrix[startI][++startJ] = nums[++finish];
        }
        // 向下移动
        for (int i = 0; i < maxI and finish < N-1; ++i) {
            matrix[++startI][startJ] = nums[++finish];
        }
        // 向左移动
        for (int i = 0; i < maxJ and finish < N-1; ++i) {
            matrix[startI][--startJ] = nums[++finish];
        }
        // 向上移动
        for (int i = 1; i < maxI and finish < N-1; ++i) {
            matrix[--startI][startJ] = nums[++finish];
        }

        maxI-=2;
        maxJ-=2;
        startJ++;
    }

    for (auto &row: matrix) {
        auto rowIter = row.begin();
        cout << *rowIter++;
        while (rowIter != row.end()) {
            cout << " " << *rowIter++;
        }
        cout << endl;
    }

    return 0;
}


#ifdef CASEID
#include "utils.h"

TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif