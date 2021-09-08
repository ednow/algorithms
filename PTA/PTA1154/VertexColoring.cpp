//
// Created by ednow on 2021/9/8.
//

#define CASEID 1154

#ifdef CASEID
#define MAIN PTA1154
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "set"

using namespace std;

int
MAIN(){
    int nodeNum{}, edgeNum{};
    cin >> nodeNum >> edgeNum;
    vector<vector<int>> graph(nodeNum);
    vector<int> color(nodeNum);

    while (edgeNum--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    int queryNum;
    cin >> queryNum;
    while (queryNum--) {
        set<int> colors;
        for (int i = 0; i < nodeNum; ++i) {
            cin >> color[i];
            colors.insert(color[i]);
        }
        bool isProper(true);
        for (int i = 0; i < nodeNum; ++i) {
            for (auto &neighbor:graph[i]) {
                if (color[neighbor] == color[i]) {
                    isProper = false;
                    break;
                }
            }
            if (!isProper) {
                break;
            }
        }
        if (isProper) {
            cout << colors.size() << "-coloring" << endl;
        }else{
            cout << "No" << endl;

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