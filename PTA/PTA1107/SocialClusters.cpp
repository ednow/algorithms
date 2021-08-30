//
// Created by ednow on 2021/8/30.
//

#define CASEID 1107

#ifdef CASEID
#define MAIN PTA1107
#else
#define MAIN main
#endif

#include "set"
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct subGraph{
    set<int> graph;
    int nodeNum{};
};


int
MAIN(){
    int nodeNum{};
    cin >> nodeNum;
    // 兴趣圈
    vector<set<int>> people(nodeNum + 1);
    for (int i = 1; i < nodeNum+1; ++i) {
        int hobbyNum{},tempHobbyId{};
        string temp;
        cin >> hobbyNum >> temp;
        while (hobbyNum--){
            cin >> tempHobbyId;
            people[i].insert(tempHobbyId);
        }
    }
    vector<subGraph> clusters;
    clusters.push_back(subGraph{.graph=set<int>(people[1].begin(), people[1].end()),.nodeNum=1});
    for (int i = 2; i < nodeNum+1; ++i) {
        // 跟之前的兄弟有一腿
        bool isClustered;
        // 找一下跟之前的兄弟有没有一腿
        for (auto & cluster: clusters) {
            set<int> res;
            set_intersection(people[i].begin(), people[i].end(), cluster.graph.begin(), cluster.graph.end(),
                             inserter(res, res.end()));
            if (!res.empty()){
                isClustered = true;
                cluster.nodeNum++;
                for (auto & hobby: people[i]) {
                    cluster.graph.insert(hobby);
                }
                break;
            }
        }

        if (!isClustered){
            clusters.push_back(subGraph{.graph=set<int>(people[i].begin(), people[i].end()),.nodeNum=1});
        }
    }

    sort(clusters.begin(), clusters.end(), [](const auto &a, const auto &b) {
        return a.nodeNum > b.nodeNum;
    });

    cout << clusters.size() << endl;
    auto iter = clusters.begin();
    cout << (*iter++).nodeNum;
    while (iter!=clusters.end()){
        cout << " " << (*iter++).nodeNum;
    }

    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif