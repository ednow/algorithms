//
// Created by ednow on 2021/8/17.
//


// 上交的时候将这一行注释掉即可
#define CASEID  1151

#ifdef CASEID
#define MAIN PTA1151
#else
#define MAIN main
#endif

#include "iostream"
#include "vector"
#include "algorithm"
#include "sstream"

using namespace std;

struct Node{
    // 节点的值
    int label{0};
    // 节点在双亲表示法中的下标
    int index{0};
    Node *left{nullptr};
    Node *right{nullptr};
    explicit Node(int label): label(label){}
};

// nodes记录当前new的对象的指针方便被回收
void
insert_nodes(
    Node * root, // 现在要插入的根节点
    vector <int> &preorderSeq, // 前序序列
    vector <int> &inorderSeq, // 中序序列
    bool isLeft,  // 现在的节点是需要插入到左边还是右边
    vector<Node *> & nodes,  // 保存所有节点的指针
    int leftIndexOfPreorderSeq, // 现在工作的preorderSeq的左边界
    int rightIndexOfPreorderSeq, // 现在工作的preorderSeq的右边界
    int leftIndexOfInorderSeq, // 现在工作的inorderSeq的左边界
    int rightIndexOfInorderSeq // 现在工作的inorderSeq的右边界
    ){
    if (leftIndexOfPreorderSeq > rightIndexOfPreorderSeq or leftIndexOfInorderSeq > rightIndexOfInorderSeq){
        return;
    }

    // 新建节点
    // 并将指针统一管理
    Node *child = new Node(preorderSeq[leftIndexOfPreorderSeq]);
    nodes.push_back(child);
    child->index = (int)(nodes.size() - 1);
    if (isLeft){
        root->left = child;
    } else{
        root->right = child;
    }

    // 孩子节点中序遍历序列中的位置
    auto indexOfRoot = find(inorderSeq.begin() + leftIndexOfInorderSeq, inorderSeq.begin() + rightIndexOfInorderSeq + 1,preorderSeq[leftIndexOfPreorderSeq]) - inorderSeq.begin();
    //  找到前序序列中左子树的部分
    // 根本不用找啊，找到根节点,左子树的个数一定是根节点的index-开始的index
    int maxLeft = (int)(indexOfRoot - leftIndexOfInorderSeq);

    // 插入左子树
    insert_nodes(child,
                 preorderSeq,
                 inorderSeq,
                 true,
                 nodes,
                 leftIndexOfPreorderSeq + 1,
                 leftIndexOfPreorderSeq + maxLeft,
                 leftIndexOfInorderSeq,
                 (int)(indexOfRoot - 1)
                 );
    // 插入右子树
    insert_nodes(child,
                 preorderSeq,
                 inorderSeq,
                 false,
                 nodes,
                 leftIndexOfPreorderSeq + maxLeft + 1,
                 rightIndexOfPreorderSeq,
                 (int) (indexOfRoot + 1),
                 rightIndexOfInorderSeq
                 );
}


int
MAIN (){
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    // pairsNum:任务请求的对数,nodesNum:一共的节点数
    int pairsNum{}, nodesNum{};
    ostringstream result;
    cin >> pairsNum >> nodesNum;
    // preorderSeq先序遍历序列，inorderSeq中序遍历序列
    vector<int> preorderSeq(nodesNum), inorderSeq(nodesNum);
    // 双亲表示法
    // 编号为nodes中的下标
    vector<int> fathers(nodesNum, -1);

    // 节点的地址们
    vector<Node *> nodes;
    // 读入中序遍历序列
    for (int i = 0; i < nodesNum; ++i) {
        cin >> inorderSeq[i];
    }
    // 读入先序遍历序列
    for (int i = 0; i < nodesNum; ++i) {
        cin >> preorderSeq[i];
    }

    // 根节点在中序遍历序列中的位置
    auto indexOfRoot = find(inorderSeq.begin(), inorderSeq.end(),preorderSeq[0]) - inorderSeq.begin();
    //  找到前序序列中左子树的部分
    int maxLeft = (int)indexOfRoot;
    // 将指针统一管理
    nodes.push_back(new Node(preorderSeq[0]));
    // 插入左子树
    insert_nodes(nodes[0],
                 preorderSeq,
                 inorderSeq,
                true, nodes,
                1, //leftIndexOfPreorderSeq + 1
                maxLeft,  // leftIndexOfPreorderSeq + maxLeft
                0, // leftIndexOfInorderSeq,
                 (int)(indexOfRoot - 1) // indexOfRoot - 1
                );

    // 插入右子树
    insert_nodes(nodes[0],
                 preorderSeq,
                 inorderSeq,
                 false, nodes,
                 maxLeft + 1, //leftIndexOfPreorderSeq + maxLeft + 1
                 (int)(preorderSeq.size() - 1), //  rightIndexOfPreorderSeq
                 (int)indexOfRoot + 1, // indexOfRoot + 1
                 (int)(inorderSeq.size() - 1) // rightIndexOfInorderSeq
                 );

    // 建立双亲表示法的树结构。这里不如直接在node里面存father
    for (const auto node:nodes) {
        // 存在左孩子
        if (node->left != nullptr){
            fathers[node->left->index] = node->index;
        }

        // 存在右孩子
        if (node->right != nullptr){
            fathers[node->right->index] = node->index;
        }
    }

    while (pairsNum--){
        // a,b需要查找的两个节点;indexOfA, indexOfB需要查找的两个节点的下标
        int a{}, b{}, indexOfA{}, indexOfB{};
        bool isAFound{false}, isBFound{false};
        vector<int> pathOfA, pathOfB;
        cin >> a >> b;
        // 找到a的下标
        auto findA = find_if(nodes.begin(), nodes.end(), [&](const auto c) { return c->label == a; });
        if (findA != nodes.end()){
            isAFound = true;
            indexOfA = (int) (findA - nodes.begin()); // 得到a在nodes中的下标
        }
        // 找到b的下标
        auto findB = find_if(nodes.begin(), nodes.end(), [&](const auto c) { return c->label == b; });
        if (findB != nodes.end()){
            isBFound = true;
            indexOfB = (int) (findB - nodes.begin());
        }
        if (!isAFound and !isBFound){
            result << "ERROR: " << a << " and " << b << " are not found.\n";
            continue;
        }

        if (!isAFound){
            result << "ERROR: " << a << " is not found.\n";
            continue;
        }

        if (!isBFound){
            result << "ERROR: " << b << " is not found.\n";
            continue;
        }

        // 找到A一直到根节点的路径
        int parent = indexOfA;
        do {
            pathOfA.insert(pathOfA.begin(), parent);
            parent = fathers[parent];  // 更新爸爸，否则会死循环
        } while (parent != -1);  // 直到根节点为止
        // 找到B一直到根节点的路径
        parent = indexOfB;
        do {
            pathOfB.insert(pathOfB.begin(), parent); // 得到b在nodes中的下标
            parent = fathers[parent];  // 更新爸爸,否则会死循环
        } while (parent != -1);  // 直到根节点为止

        // 检查A如果出现在B的路径上
        if (find(pathOfB.begin(), pathOfB.end(), indexOfA) != pathOfB.end()){
            result << a << " is an ancestor of " << b << ".\n";
            continue;
        }
        // 检查B有没有出现在A的路径上
        if (find(pathOfA.begin(), pathOfA.end(), indexOfB) != pathOfA.end()){
            result << b << " is an ancestor of " << a << ".\n";
            continue;
        }
        auto iterA = pathOfA.begin();
        auto iterB = pathOfB.begin();
        for (;iterA != pathOfA.end() and iterB != pathOfB.end();iterA++,iterB++){
            if (*iterA != *iterB){  //是迭代器的值比较，不是迭代器比较
                break;
            }
        }
        result << "LCA of " << a << " and " << b << " is " << nodes[pathOfA[iterA - pathOfA.begin() - 1]]->label << ".\n";


    }

    cout << result.str();
    // 防止内存泄漏，释放掉分配的内存。
    // 好像只有一个loop也不存在内存泄漏的问题：下次使用智能指针解决
    for_each(nodes.begin(), nodes.end(), [](auto a) { delete a; });
    return 0;
}

#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif
