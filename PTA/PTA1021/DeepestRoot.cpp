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
    vector<vector<int>> &paths,
    // 此次dfs访问到的节点
    vector<int> &path,
    // 该节点是否被访问过
    vector<bool> &isVisited,
    // 总的节点数
    int &nodeNum,
    // 记录访问栈,需要加的数据结构
    vector<int> &stack
){

    path.push_back(source);
    stack.push_back(source);
    // 一定要写上，防止死循环
    isVisited[source] = true;
    for (int i = 0; i < nodeNum; ++i) {
        if (graph[source][i] and !isVisited[i]){
            dfs(i, graph, isLeaf, paths, path, isVisited, nodeNum, stack);
        }
    }
    // 这里一定要放在后面，防止一开始选中的就是根节点会出bug
    if (isLeaf[source]){
        paths.emplace_back(stack.begin(), stack.end());
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

    // 存放所有的路径
    vector<vector<int>> paths;
//    paths.reserve(accumulate(isLeaf.begin(), isLeaf.end(), 0));
    paths.reserve(nodeNum);
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

    // 节点中还有元素
    while (!nodes.empty()){
        vector<int> tempPath;
        vector<int> stack;
        dfs(*nodes.begin(), graph, isLeaf, paths, tempPath, isVisited, nodeNum, stack);
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

    // 求最深的根节点们
    // 下标0代表外层循环的路径的长度
    // 下标1代表内层循环的路径长度
    // 下标2代表内外层循环合并的路径长度
//    没有path会死循环？
    vector<int> lens(3, 0);
    int maxLen{INT32_MIN};
    for (int i = 0; i < paths.size()-1; ++i) {
        for (int j = i+1; j < paths.size(); ++j) {
            lens[0] = (int)paths[i].size();
            lens[1] = (int)paths[j].size();

            // 计算合并之后的长度
            auto iter1 = paths[i].begin();
            auto iter2 = paths[j].begin();
            // 这里是等于
            while (*iter1 == *iter2){
                iter1++;
                iter2++;
            }
            //   2 * (iter1 - paths[i].begin() + 1) + 1)
            // = 2 * (iter1 - paths[i].begin()) - 1)
            lens[2] = (int) (lens[0] + lens[1] - 2 * (iter1 - paths[i].begin()) + 1);
            auto maxLenElem = max_element(lens.begin(), lens.end());
            if (*maxLenElem > maxLen){
                maxLen = *maxLenElem;
                maxLenRoots.clear();
            }

            // 外循环的
            if (*maxLenElem == lens[0]){
                maxLenRoots.insert(*paths[i].begin());
                // c++切片最后一个元素是*(paths[i].end()-1)
                maxLenRoots.insert(*(paths[i].end()-1));
            }
            if (*maxLenElem == lens[1]){
                maxLenRoots.insert(*paths[j].begin());
                maxLenRoots.insert(*(paths[j].end()-1));
            }

            if (*maxLenElem == lens[2]){
                maxLenRoots.insert(*(paths[i].end() - 1));
                maxLenRoots.insert(*(paths[j].end() - 1));
            }

        }
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