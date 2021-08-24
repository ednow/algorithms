//
// Created by ednow on 2021/8/24.
//

//
// Created by ednow on 2021/8/23.
//

// 本稿未ac，感觉第一份该点小bug直接减枝也能过

#define CASEID 1103

#ifdef CASEID
#define MAIN PTA1111111111111111111111111111111111
#else
#define MAIN main
#endif

#include "vector"
#include "iostream"
#include "cmath"
#include "numeric"
#include "algorithm"
#include "map"
using namespace std;

void
dfs(
        // 这次要加入的数
        int start,
        // 要求的数
        const int &num,
        // 现在stack中元素的和
        int &numByNow,
        // 幂
        const int &p,
        // 最大的底
        const int &maxBase,
        // stack的长度
        const int &len,
        // 现在stack中的元素
        vector<int> &stack,
        // 存放结果序列
        vector<vector<int>> &result
){
    // 先压进结果中
    stack.push_back(start);
    start = (int) pow(start, p);
    numByNow += start;
    // 如果超过长度了退栈
    if (len < stack.size()){
        numByNow -= start;
        stack.pop_back();
        return;
    }

    // 如果结果太大了退栈
    if (numByNow > num){
        numByNow -= start;
        stack.pop_back();
        return;
    }

    // 结果相等退栈
    if (numByNow == num){
        // 满足条件压入结果中
        if (stack.size() == len){
            result.emplace_back(stack.begin(), stack.end());
        }
        numByNow -= start;
        stack.pop_back();
        return;
    }

    for (int i = start; i >= 1 ; --i) {
        dfs(i, num, numByNow, p, maxBase, len, stack, result);
    }

    // 跟随函数一起退栈
    numByNow -= start;
    stack.pop_back();
}


int
MAIN(){
    // n需要求的数
    // k递归的最大深度
    // p次数
    int n{}, k{}, p{};
    cin >> n >> k >> p;
    // 换底公式
    int maxBase = (int) (log(n / k) / log(p));
    // 大于要表示的数
    if (pow(maxBase, p) * k < n){
        maxBase++;
    }
    map<int, int> numToBase;
    for (int i = maxBase; i > 0; --i) {
        numToBase[(int) pow(i, p)] = i;
    }
    // 存放结果序列
    vector<vector<int>> result;
    // 递归开始的0不计
    int numByNow;
    vector<int> stack;

    // 递归开始
    dfs(maxBase, n, numByNow, p, maxBase, k, stack, result);

    if (result.empty()){
        cout << "Impossible";
    }else{
        auto maxElem = max_element(result.begin(), result.end(), [&](const auto &a, const auto &b) {
            auto sumOfA = accumulate(a.begin(), a.end(),0,[&](const auto &a, const auto &b){
                return a + numToBase[b];
            });
            auto sumOfB = accumulate(b.begin(), b.end(),0,[&](const auto &a, const auto &b){
                return a + numToBase[b];
            });
            if (sumOfA != sumOfB) return sumOfA < sumOfB;
            auto iter1 = a.begin();
            auto iter2 = b.begin();
            while (*iter1 == *iter2 and iter1 != a.end()) {
                iter1++;
                iter2++;
            }
            return *iter1 < *iter2;
        });

        cout << n << " = ";
        auto iter = (*maxElem).begin();
        cout << *iter++ << "^" << p;
        while (iter != (*maxElem).end()){
            cout << " + " << *iter++ << "^" << p;
        }
    }
    cout << endl;

    return 0;
}
