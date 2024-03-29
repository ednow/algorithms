//
// Created by ednow on 2021/8/23.
//

#define CASEID 1103

#ifdef CASEID
#define MAIN PTA1103
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
        // 这次要加入的数的下标
        int start,
        // 要求的数
        const int &num,
        // 现在stack中元素的和
        int &numByNow,
        // 现在指针的位置
        int p,
        // 最大的底
        const vector<int> &numbers,
        // 指针最大长度
        const int &len,
        // 现在stack中的元素
        vector<int> &stack,
        // 存放结果序列
        vector<vector<int>> &result,
        // 是否存在
        bool &isExited
){
    // 如果超过长度了退栈
    if (len < p){
        return;
    }

    // 结果相等退栈
    // 满足条件压入结果中
    if (numByNow == num){
        result.emplace_back(stack.begin(), stack.end());
        isExited = true;
        return;
    }

    // 太大了，往小的值搜索
    for (int j = start; j < (int)numbers.size() ; j++) {
        int i = numbers[j];
        // 记住当前的结果，退栈的时候恢复
        int rawPointerNum = stack[p];
        int rawNumByNow = numByNow;
        numByNow = i + numByNow - rawPointerNum;
        stack[p] = i;
        // 如果结果更小，指针向后搜索
        if (numByNow <= num){
            dfs(j, num, numByNow, p+1, numbers, len, stack, result, isExited);
        }
        stack[p] = rawPointerNum;
        numByNow = rawNumByNow;
    }
}


int
MAIN(){
    // n需要求的数
    // k递归的最大深度
    // p次数
    int n{}, k{}, p{};
    cin >> n >> k >> p;
    // 换底公式
    int maxBase = (int) pow(n-k+1, 1.0/p);
//    int minBase = (int) pow(n/k, 1.0/p);
    // 大于要表示的数
    if (pow(maxBase, p) < n-k+1){
        maxBase++;
    }
    map<int, int> numToBase;
    numToBase[1] = 1;
    vector<int> numbers;
    numbers.reserve(maxBase);
    for (int i = maxBase; i > 1; --i) {
        int num = (int) pow(i, p);
        numbers.push_back(num);
        numToBase[num] = i;
    }
    // 存放结果序列
    vector<vector<int>> result;
    int numByNow=k;
    vector<int> stack(k,1);
    bool isExisted;
    // 递归开始
    dfs(0, n, numByNow, 0, numbers, k, stack, result, isExisted);

    if (!isExisted){
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
//        iter++;
        cout << numToBase[*iter++] << "^" << p;
        while (iter != (*maxElem).end()){
            cout << " + " << numToBase[*iter++] << "^" << p;
        }
    }
    cout << endl;

    return 0;
}


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif