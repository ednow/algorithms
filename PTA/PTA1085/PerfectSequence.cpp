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

using namespace std;

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
    while ((*nums.begin()) * p < *nums.rbegin()){
        nums.erase(nums.begin());
    }
    cout << nums.size();

    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif