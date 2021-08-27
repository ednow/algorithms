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


void dfs(int start, int end, vector<int> &factors, vector<int> &answer){
    if (end==1){
        vector<vector<int>> consecutiveFactors;
        int prev = 0;
        for (int i = 1; i < factors.size(); ++i) {
            if (factors[i-1] + 1 != factors[i]){
                consecutiveFactors.emplace_back(factors.begin() + prev, factors.begin() + i);
                prev = i;
            }
        }
        // 先找出最长的，再找乘积最小的
        auto result = max_element(consecutiveFactors.begin(), consecutiveFactors.end(), [](const auto &a, const auto &b) {
            if (a.size() != b.size()) return a.size() < b.size();
            return a>b;
        });
        if (answer.size() < (*result).size()){
            answer = *result;
        }

        return;
    }
    for (int i = start; i <= end; ++i) {
        if (end % i == 0){
            factors.push_back(i);
            dfs(i, end / i, factors, answer);
            break;
        }
    }
}



int
MAIN(){
    int num;
    vector<int> factors;
    cin >> num;

    vector<int> answer;
    for (int i = 2; i <= (int)sqrt(num) ; ++i) {
        factors.clear();
        dfs(i, num, factors,answer);
    }


    // 输出结果
    cout << answer.size();
    auto iter = answer.begin();
    cout << *iter++;
    while (iter != answer.end()){
        cout << " " << *iter++;
    }

    return 0;
}


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif