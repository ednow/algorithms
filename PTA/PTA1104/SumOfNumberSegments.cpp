//
// Created by ednow on 2021/9/10.
//

#define CASEID 1104
#ifdef CASEID
#define MAIN PTA1104
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "iomanip"

using namespace std;

int
MAIN() {
    int N;
    cin >> N;
    vector<double> num(N,0);
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }
    double result{};
    for (int i = 0; i < N; ++i) {
        result += num[i] * (i + 1) * (N - i);
    }
    cout << setprecision(2) << fixed << result;

    return 0;
}

#ifdef CASEID
#include "ednow/utils.h"

TEST(pta, CASEID){
    DO_TEST(CASEID)
}
#endif