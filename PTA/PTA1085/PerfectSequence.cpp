//
// Created by ednow on 2021/8/30.
//

#define CASEID 1085

#ifdef CASEID
#define MAIN PTA1085
#else
#define MAIN main
#endif

#include "vector"
#include "iostream"
#include "set"
#include "limits"

using namespace std;

void dfs(set<int> &nums, int &maxSize, int&p) {
    if ((*nums.begin()) * p >= *nums.rbegin()){
        if (nums.size() > maxSize){
            maxSize = (int)nums.size();
        }
        return;
    }
    if (nums.empty()){
        return;
    }
    set<int> tempNums1 = nums;
    set<int> tempNums2 = nums;
    if ((*nums.begin()) * p < *nums.rbegin()){
        tempNums1.erase(tempNums1.begin());
        tempNums2.erase(*tempNums1.rbegin());
        dfs(tempNums1, maxSize, p);
        dfs(tempNums2, maxSize, p);
    }


}


int
MAIN(){
    int numLen{}, p{};
    cin >> numLen >> p;
    set<int> nums;
    int num{};
    for (int i = 0; i < numLen; ++i) {
        cin >> num;
        nums.insert(num);
    }
    int maxSize{INT32_MIN};
    dfs(nums, maxSize, p);
    cout << maxSize;

    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif