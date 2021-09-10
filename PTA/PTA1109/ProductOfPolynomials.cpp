//
// Created by ednow on 2021/9/10.
//

#define CASEID 1109
#ifdef CASEID
#define MAIN PTA1109
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "iomanip"
#include "map"
#include "set"

using namespace std;

int
MAIN() {
    map<int, long double> a;
    map<int, long double> b;
    int Len;
    // 读入A
    cin >> Len;
    while (Len--) {
        int c;
        long double d;
        cin >> c >> d;
        a[c] = d;
    }
    // 读入B
    cin >> Len;
    while (Len--) {
        int c;
        long double d;
        cin >> c >> d;
        b[c] = d;
    }
    // 得到乘积的结果
    map<int, long double> result;
    for (auto& i:a) {
        for (auto& j:b) {
            result[i.first + j.first] += i.second * j.second;
        }
    }

    cout << result.size();
    auto iter = result.rbegin();
    while (iter != result.rend()) {
        cout << " " << (*iter).first << " " << setprecision(1) << fixed << (*iter).second;
        iter++;
    }

    return 0;
}

#ifdef CASEID
#include "ednow/utils.h"

TEST(pta, CASEID){
    DO_TEST(CASEID)
}
#endif