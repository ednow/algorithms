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
#include "algorithm"
using namespace std;

int
MAIN(){
    long long numLen{}, p{};
    cin >> numLen >> p;
    vector<long long> nums;
    nums.reserve(numLen);
    long long num{};
    for (long long i = 0; i < numLen; ++i) {
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    long long maxSize{};
    for (long long i = 0; i < numLen; ++i) {
        // i控制左指针
        // maxSize控制右指针
        while (i + maxSize < numLen and nums[i + maxSize] <= nums[i] * p) {
            maxSize++;
        }
    }

    cout << maxSize;

    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif