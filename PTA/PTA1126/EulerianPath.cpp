//
// Created by ednow on 2021/8/28.
//

#define CASEID 1126

#ifdef CASEID
#define MAIN PTA1126
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "numeric"

using namespace std;

int
MAIN(){
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;
    vector<int> degrees(nodeNum + 1, 0);
    while (edgeNum--){
        int a, b;
        cin >> a >> b;
        degrees[a]++;
        degrees[b]++;
    }
    vector<int> isNotEven;
    isNotEven.reserve(nodeNum + 1);
    for (auto &a: degrees) {
        isNotEven.push_back(a % 2);
    }
    int notEvenNum = accumulate(isNotEven.begin(), isNotEven.end(), 0, plus<>());
    auto a = degrees.begin()+1;
    for (; a != degrees.end() - 1; ++a) {
        cout << *a << " ";
    }
    cout << *a << endl;
    switch (notEvenNum) {
        case 0:
            cout << "Eulerian";
            break;
        case 2:
            cout << "Semi-Eulerian";
            break;
        default:
            cout << "Non-Eulerian";
            break;
    }

    return 0;
};


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif