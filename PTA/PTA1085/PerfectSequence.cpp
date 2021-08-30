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
#include "queue"

struct item{
    int low{};
    int high{};
};

using namespace std;

void bfs(vector<int> &nums, int &maxSize, int&p) {
    queue<item> q;
    q.push(item{.low=0, .high=(int)nums.size() - 1});

    while (!q.empty()){
        auto head = q.front();
        if (head.high < head.low) {
            q.pop();
            continue;
        }

        if (nums[head.low] * p >= nums[head.high]){
            if (head.high - head.low + 1 > maxSize){
                maxSize = head.high - head.low + 1;
            }
            // 不用push进队列里面，因为此时已经是最大的了
        }else{
            q.push(item{.low=head.low + 1, .high=head.high});
            q.push(item{.low=head.low, .high=head.high - 1});
        }

        q.pop();
    }
}


int
MAIN(){
    int numLen{}, p{};
    cin >> numLen >> p;
    vector<int> nums;
    nums.reserve(numLen);
    int num{};
    for (int i = 0; i < numLen; ++i) {
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());
    int maxSize{};
    bfs(nums, maxSize, p);
    cout << maxSize;

    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif