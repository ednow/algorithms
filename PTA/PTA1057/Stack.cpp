//
// Created by ednow on 2021/9/2.
//
#define CASEID 1057

#ifdef CASEID
#define MAIN PTA1057
#else
#define MAIN main
#endif

#include "string"
#include "vector"
#include "iostream"
#include "set"

using namespace std;

//int get_median(vector<int> &stack){
//    int result{};
//
//}

int
MAIN(){
    int operationNum{};
    string operation;
    cin >> operationNum;
    // 栈
    vector<int> stack;
    // 用来求中位数
    multiset<int> mirrorStack;
    while (operationNum--) {
        cin >> operation;
        if (operation == "Pop"){
            if (stack.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            cout << *stack.rbegin() << endl;
            mirrorStack.erase(mirrorStack.lower_bound(*stack.rbegin()));
            stack.pop_back();
            continue;
        }

        if (operation == "PeekMedian"){
            if (stack.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            auto iter = mirrorStack.begin();
            int n = (int)(mirrorStack.size()+1)/ 2-1;
            advance(iter, n);
            cout << *iter << endl;
            continue;
        }

        if (operation == "Push"){
            int numToPush;
            cin >> numToPush;
            stack.push_back(numToPush);
            mirrorStack.insert(numToPush);
            continue;
        }

    }
    return 0;
}


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif