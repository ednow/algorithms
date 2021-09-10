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

    // 找到所有的次数
    set<int> powers;
    for (auto & temp:a) {
        powers.insert(temp.first);
    }
    for (auto & temp:b) {
        powers.insert(temp.first);
    }

    // 得到乘积的结果
    map<int, long double> result;
    for (auto & power: powers) {
        if (a.find(power) != a.end() and b.find(power) != b.end()) {
//            long double times = a[power] * b[power];
//            if (times != 0) {
            result[power] = a[power] * b[power];
//            }
            continue;
        }

        if (a.find(power) != a.end()) {
            result[power] = a[power];
            continue;
        }


        if (b.find(power) != b.end()) {
            result[power] = b[power];
            continue;
        }
    }

    cout << result.size();
    auto iter = result.rbegin();
    while (iter != result.rend()) {
        cout << " " << (*iter).first << " " << (*iter).second;
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