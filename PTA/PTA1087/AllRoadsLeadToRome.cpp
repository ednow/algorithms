//
// Created by ednow on 2021/8/21.
//

#define CASEID 1087  // 上交时注释


#ifdef CASEID
#define MAIN PTA1087
#else
#define MAIN main
#endif


#include "ios"
#include "iostream"
#include "vector"
#include "memory"
//#include "stack"
#include "string"
#include "map"
#include "algorithm"
#include "limits"
#include "numeric"

using namespace std;


// dijkstra求出来的一些信息
struct cityInfo{
    // 城市的唯一标识符
    int index{};
    // 累计路径长度
    int weight{INT32_MAX};
    // 存放父亲节点们的唯一标识符
    vector<int> parent{};
    explicit cityInfo(int index): index(index){}
};

struct pathInfo{
    // path的唯一标识符
    int idx{};
    // path中的节点数
    int len{};
    // 总的开心度
    int sumOfHappiness{};
};

void
get_path(vector<shared_ptr<cityInfo>> &nodes, vector<vector<int>> &paths, vector<int> &stack, int source, int destination){
    stack.push_back(source);
    if (source == destination){
        paths.emplace_back(stack.begin(), stack.end());
        stack.pop_back();
        return;
    }

    for (auto & parent:nodes[source]->parent) {
        get_path(nodes, paths, stack, parent, destination);
    }
    stack.pop_back();
}


int
MAIN(){
    // cityNum城市的数量
    // roadNum道路的数量
    int cityNum{}, roadNum{};
    // 出发点城市
    string sourceCity;
    cin >> cityNum >> roadNum >> sourceCity;
    // 通过名字找到存储结构中的index
    map<string, int> nameToIdx;
    // 通过index找到名字
    map<int, string> idxToName;
    // 每一个城市的开心度
    // 这里读入需要注意
    vector<int> happiness(cityNum);
    nameToIdx[sourceCity] = 0;
    idxToName[0] = sourceCity;
    // 读取每个城市的开心度和nameToIdx
    for (int i = 1; i < cityNum; ++i) {
        string name;
        cin >> name;
        nameToIdx[name] = i;
        idxToName[i] = name;
        cin >> happiness[i];
    }
    // 图的零阶矩阵存储结构
    vector<vector<int>> graph(cityNum, vector<int>(cityNum));
    while (roadNum--){
        string a, b;
        int weight;
        cin >> a >> b >> weight;
        graph[nameToIdx[a]][nameToIdx[b]] = weight;
        graph[nameToIdx[b]][nameToIdx[a]] = weight;
    }

    // dijkstra
    vector<shared_ptr<cityInfo>> nodes(cityNum);
    for (int i = 0; i < cityNum; ++i) {
        nodes[i] = make_shared<cityInfo>(i);
    }
    // 反向dijkstra
    // 本来应该是sourceCity为源，为了方便求path，这里反向dijkstra
    nodes[nameToIdx["ROM"]]->weight = 0;
    vector<shared_ptr<cityInfo>> unselectedNodes(nodes.begin(), nodes.end());
    while (!unselectedNodes.empty()){
        auto node = min_element(unselectedNodes.begin(), unselectedNodes.end(), [](const auto &a, const auto &b) {
            return a->weight < b->weight;
        });
        for (int i = 0; i < cityNum; ++i) {
            if (graph[(*node)->index][i]!=0){
                int newWeight = graph[(*node)->index][i] + (*node)->weight;
                if (newWeight < nodes[i]->weight){
                    nodes[i]->weight = newWeight;
                    nodes[i]->parent.clear();
                    nodes[i]->parent.push_back((*node)->index);
                    continue;
                }
                if (newWeight == nodes[i]->weight){
                    nodes[i]->parent.push_back((*node)->index);
                    continue;
                }
            }
        }
        unselectedNodes.erase(node);
    }
    vector<vector<int>> paths;
    vector<int> stack;
    get_path(nodes, paths, stack,nameToIdx[sourceCity], nameToIdx["ROM"]);

    vector<pathInfo> pathInfos(paths.size());
    // 生成挑选参量
    for (int i = 0; i < paths.size(); ++i) {
        pathInfos[i].idx = i;
        pathInfos[i].len = (int)paths[i].size();
        pathInfos[i].sumOfHappiness = accumulate(paths[i].begin(), paths[i].end(), 0,
                                                 [&](const auto &a, const auto &b) {
                                                     return a + happiness[b];
                                                 });
    }

    //max_element也是比较重载<号。？
    auto result = max_element(pathInfos.begin(), pathInfos.end(), [](const auto &a, const auto &b) {
        if (a.sumOfHappiness != b.sumOfHappiness) return a.sumOfHappiness < b.sumOfHappiness;
        return a.len > b.len;
    });
    cout << paths.size() << " " << nodes[nameToIdx[sourceCity]]->weight << " " ;
    cout << (*result).sumOfHappiness << " "  << (*result).sumOfHappiness / ((*result).len - 1) << endl;
    cout << sourceCity;
    for (int i = 1; i < (*result).len; ++i) {
        cout << "->" << idxToName[paths[(*result).idx][i]];
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


