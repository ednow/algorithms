//
// Created by ednow on 2021/8/17.
//

#include "Heaps.h"

#include "vector"
#include "ios"
#include "iostream"
#include "sstream"

using namespace std;

struct Node{
    int label{0};
    Node *left{nullptr};
    Node *right{nullptr};

//    Node() = default;;

//    explicit Node(int label){
//        this -> label = label;
//    }
    bool operator < (const Node & other) const{
        return label < other.label;
    }

    bool operator <= (const Node & other) const{
        return label <= other.label;
    }

    bool operator > (const Node & other) const{
        return label > other.label;
    }

    bool operator >= (const Node & other) const{
        return label >= other.label;
    }
};

void postorder_traversal(Node * root,  vector<int> &result){
    if (root == nullptr){
        return;
    }
    postorder_traversal(root->left, result);
    postorder_traversal(root->right, result);
    result.push_back(root->label);
}

void
judge_one_case(int nodesNum, ostringstream & result){
    // 存放结果
//    ostringstream result;
    vector<Node> nodes(nodesNum);
    for (int i = 0; i < nodesNum; ++i) {
        cin >> nodes[i].label;
    }
    nodesNum -= 1;

    bool isMayMaxHeap = true;
    // 第一个大于第二个元素，有可能是大顶堆
    if (nodes[0]>nodes[1]){
        isMayMaxHeap = true;
    } else{
        isMayMaxHeap = false;
    }

    // 是不是堆
    bool isHeap = true;
    int leftIdx = -1;
    int rightIdx = -1;
    // 检查到底是不是满足堆的定义，并且根据二叉树的链式存储结构建立二叉树
    for (int i = 0; i < (int)(nodesNum / 2 + 1); ++i) {
        // 左孩子的下标
        leftIdx = i * 2 + 1;
        // 右孩子的下标
        rightIdx = i * 2 + 2;
        // 有可能是大顶堆
        if (isMayMaxHeap){
            if (leftIdx <= nodesNum){
                // 既然之前觉得是大顶堆就检查一下，现在这个符不符合，如果不符合,就设为False
                if (isHeap){
                    if (nodes[i] < nodes[leftIdx]){
                        isHeap = false;
                    }
                }
                // 插入左孩子
                nodes[i].left = & nodes[leftIdx];
            }

            if (rightIdx <= nodesNum){
                // 既然之前觉得是大顶堆就检查一下，现在这个符不符合，如果不符合,就设为False
                if (isHeap){
                    if (nodes[i] < nodes[rightIdx]){
                        isHeap = false;
                    }
                }
                // 插入左孩子
                nodes[i].right = & nodes[rightIdx];
            }
        }else{
            if (leftIdx <= nodesNum){
                // 既然之前觉得是小顶堆就检查一下，现在这个符不符合，如果不符合,就设为False
                if (isHeap){
                    if (nodes[i] >= nodes[leftIdx]){
                        isHeap = false;
                    }
                }
                // 插入左孩子
                nodes[i].left = & nodes[leftIdx];
            }

            if (rightIdx <= nodesNum){
                // 既然之前觉得是小顶堆就检查一下，现在这个符不符合，如果不符合,就设为False
                if (isHeap){
                    if (nodes[i] >= nodes[rightIdx]){
                        isHeap = false;
                    }
                }
                // 插入左孩子
                nodes[i].right = & nodes[rightIdx];
            }
        }
    }
    if (isHeap){
        if (isMayMaxHeap){
            result << "Max Heap\n";
        } else{
            result << "Min Heap\n";
        }
    }else{
        result << "Not Heap\n";
    }
    vector<int> traversal;

    postorder_traversal(&nodes[0], traversal);  // 为什么不能直接对nodes[0]取地址？提示左值,如果传递指针的引用
    for (int i = 0; i < traversal.size() - 1; ++i) {
        result << traversal[i] << " ";
    }
    result << traversal[traversal.size() - 1];
    result << "\n";
}

int Heaps(){
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    ostringstream result;
    int caseNum{},nodesNum{};
    cin >> caseNum >> nodesNum;
    while (caseNum--){
        judge_one_case(nodesNum, result);
    }
    cout << result.str();

    return 0;
}


TEST(TestCase, test_PTA_1147) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1147/data.json");
    in >> j;
    ifstream configFile("../config.json");
    configFile >> config;
    vector<map<string, string>> testcases;
    //    &config
    copy_if(j.begin(), j.end(), std::back_inserter(testcases), [&](auto i) { return i["id"] == config["testCaseId"]; });
    if (testcases.empty()) {
        testcases = j.get<vector<map<string, string>>>();
    }
    for (auto &testcase :testcases) {
        cout << "--------------------------------" << endl;
        cout << "testCaseId:" << testcase["id"] << " testing" << endl;

        string s = testcase["data"];
        istringstream oss(s);
        cin.rdbuf(oss.rdbuf());  // 将测试用例读进cin

        std::stringstream redirectStream;
        std::streambuf *oldbuf = std::cout.rdbuf(redirectStream.rdbuf());

        Heaps();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}