//
// Created by ednow on 2021/8/23.
//

#define CASEID 1021

#ifdef CASEID
#define MAIN PTA1021
#else
#define MAIN main
#endif


#include "iostream"
#include "vector"
#include "numeric"
#include "set"
#include "unordered_set"
#include "algorithm"
#include "limits"

using namespace std;


void
dfs(
        // 现在的dfs从哪个节点开始访问
        int source,
        // 图
        vector<vector<bool>> &graph,
        // 下标所对应的叶子节点是不是叶子节点
        vector<bool> &isLeaf,
        // 所有找到的路径
        vector<int> &maxLenRoots,
        // 此次dfs访问到的节点
        vector<int> &path,
        // 该节点是否被访问过
        vector<bool> &isVisited,
        // 总的节点数
        int &nodeNum,
        // 记录访问栈,需要加的数据结构
        vector<int> &stack,
        int &maxLen
) {
    path.push_back(source);
    stack.push_back(source);
    // 一定要写上，防止死循环
    isVisited[source] = true;
    for (int i = 0; i < nodeNum; ++i) {
        if (graph[source][i] and !isVisited[i]) {
            dfs(i, graph, isLeaf, maxLenRoots, path, isVisited, nodeNum, stack, maxLen);
        }
    }
    // 这里一定要放在后面，防止一开始选中的就是根节点会出bug
    if (isLeaf[source]) {
        if (stack.size() > maxLen){
            maxLen = (int) stack.size();
            maxLenRoots.clear();
        }
        if (stack.size() == maxLen){
            maxLenRoots.push_back(source);
        }
    }
    stack.pop_back();
}


// 找到最大的节点们
void
findMaxRoots(
        // 图
        vector<vector<bool>> &graph,
        // 这份图是不是树
        bool &isTree,
        // 最长路径的根节点们
        set<int> &maxLenRoots,
        // 如果不是树，图中的联通分量数是多少个
        int &componentNum
){

    // 通过图获取点的数量
    int nodeNum = (int)graph.size();
    // 得到叶子节点
    vector<bool> isLeaf(nodeNum, false);
    for (int i = 0; i < nodeNum; ++i) {
        // 出度为1一定是叶子节点
        if (accumulate(graph[i].begin(), graph[i].end(), 0)==1){
            isLeaf[i] = true;
        }
    }

    // 最高的树
    int maxLen{};

    int dfsTimes{};
    unordered_set<int> nodes;
    // 节点从1开始编号
    for (int i = 1; i < nodeNum; ++i) {
        nodes.insert(i);
    }
    nodes.erase(0);

    // 这个节点是否被访问过
    vector<bool> isVisited(nodeNum);
    isVisited[0] = true;

    vector<int> tempMaxLenRoots;

    // 节点中还有元素
    while (!nodes.empty()){
        vector<int> tempPath;
        vector<int> stack;
        dfs(*nodes.begin(), graph, isLeaf, tempMaxLenRoots, tempPath, isVisited, nodeNum, stack, maxLen);
        for (auto &a:tempPath) {
            nodes.erase(a);
        }
        dfsTimes++;
    }
    if (dfsTimes>1) {
        isTree = false;
        componentNum = dfsTimes;
        return;
    }

    for (auto & a: tempMaxLenRoots) {
        maxLenRoots.insert(a);
    }

    // 第二轮dfs

    nodes.clear();
    // 节点从1开始编号
    for (int i = 1; i < nodeNum; ++i) {
        nodes.insert(i);
    }
    nodes.erase(0);

    // 这个节点是否被访问过
    isVisited.assign(nodeNum, false);
    isVisited[0] = true;

    tempMaxLenRoots.clear();

    // 节点中还有元素
    while (!nodes.empty()){
        vector<int> tempPath;
        vector<int> stack;
        // 随便选一个最深的根访问
        dfs(*maxLenRoots.begin(), graph, isLeaf, tempMaxLenRoots, tempPath, isVisited, nodeNum, stack, maxLen);
        for (auto &a:tempPath) {
            nodes.erase(a);
        }
    }

    for (auto & a: tempMaxLenRoots) {
        maxLenRoots.insert(a);
    }
}


int
MAIN(){
    // edgeNum边的数量，maxLen最大长度
    int nodeNum{};
    cin >> nodeNum;
    if (nodeNum==1){
        cout << 1 << endl;
        return 0;
    }

    // 邻接举证存储结构
    vector<vector<bool>> graph(nodeNum+1, vector<bool>(nodeNum+1, false));

    // 读边
    for (int i = 1; i < nodeNum; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    // 这个图是不是树
    bool isTree{true};
    // 如果不是树有多少个连通分量
    int componentNum{};
    // 最大长度的根们
    set<int> maxLenRoots;
    findMaxRoots(graph, isTree, maxLenRoots, componentNum);

    if (isTree){
        auto iter = maxLenRoots.begin();
        cout << *iter++;
        while (iter!=maxLenRoots.end()){
            cout << endl << *iter++;
        }
    }else{
        cout << "Error: " << componentNum << " components";
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