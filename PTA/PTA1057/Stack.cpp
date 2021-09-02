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

using namespace std;

int
MAIN(){
    int operationNum{};
    string operation;
    cin >> operationNum;
    vector<int> stack;
    while (operationNum--) {
        cin >> operation;
        if (operation == "Pop"){
            if (stack.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            cout << *stack.rbegin() << endl;
            stack.pop_back();
            continue;
        }

        if (operation == "PeekMedian"){
            if (stack.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            cout << stack[stack.size()/2] << endl;
//            stack.erase(stack.begin()+stack.size()/2);
            continue;
        }

        if (operation == "Push"){
            int numToPush;
            cin >> numToPush;
            stack.push_back(numToPush);
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