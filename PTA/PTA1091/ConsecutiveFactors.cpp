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


void dfs(int start, int end, vector<int> &factors){
    factors.push_back(start);
    if (end % (start+1) == 0){
        dfs((start+1), end / (start+1), factors);
    }
}



int
MAIN(){
    int num;
    vector<int> factors;
    cin >> num;

    vector<int> answer;
    for (int i = 2; i <= (int)sqrt(num) ; ++i) {
        if (num%i==0){
            factors.clear();
            dfs(i, num, factors);
            if (answer.size() < factors.size()){
                answer = factors;
            }
        }
    }


    // 输出结果
    cout << answer.size() << endl;
    auto iter = answer.begin();
    cout << *iter++;
    while (iter != answer.end()){
        cout << "*" << *iter++;
    }

    return 0;
}


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif