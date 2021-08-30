//
// Created by ednow on 2021/8/30.
//

#define CASEID 1044

#ifdef CASEID
#define MAIN PTA1044
#else
#define MAIN main
#endif

#include "vector"
#include "iostream"
#include "numeric"
#include "map"

using namespace std;



int
MAIN(){
    int diamondLen, cost;
    cin >> diamondLen >> cost;

    vector<int> diamonds(diamondLen, 0);
    for (int i = 0; i < diamondLen; ++i) {
        cin >> diamonds[i];
    }

    int start{};
    int end=1;
    int sum{};
    // 与期望的差 -> [开始，结尾]
    map<int, vector<vector<int>>> result;

    while (end != diamondLen) {
        sum = accumulate(diamonds.begin()+start, diamonds.begin()+end+1, 0, plus<>());
        if (sum<cost){
            end++;
        }
        if (sum>=cost){
            result[sum - cost].emplace_back(vector<int>({start, end}));
            start++;
        }
    }
    for (auto & path:(*result.begin()).second) {
        cout << path[0]+1 << "-" << path[1]+1 << endl;
    }

    return 0;
}


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif