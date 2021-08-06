//
// Created by ednow on 2021/8/6.
//

#include "PATJudge.h"


#include "ios"
#include "iostream"
#include "iomanip"
#include "vector"
#include "sstream"
#include "limits"
#include "algorithm"
#include "numeric"  // inner_product

using namespace std;

typedef struct record_ {
    vector<bool> isSummit;  //是否提交过题目
    int perfectNum;  // 满分的题目的总数
    int rank; // 用户排名
    int id;  // 用户id，未排序前下标也可表示id
    vector<int> scores;  // 每一项的成绩
    int total; // 总成绩

}record;

#define MAX_USERS_NUM 100000

int PATJudge(){
    // N用户数,K题目数,M提交数,
    // id临时变量用户id,problemId临时变量问题编号,score临时变量成绩,
    int N{}, K{}, M{},id{},problemId{},score{};
    // 读入用户数, 题目数,提交数
    cin >> N >> K >> M;

    // 最后输出的结果
    ostringstream result;
    // 满分
    vector<int> fullScore(K);
    // 创建N个user的信息表,每个user有K个成绩列表,初始化
//    vector<record> records(N, record{.scores = vector<int>(K, -1)});
    vector<record> records(MAX_USERS_NUM, record{.isSummit = vector<bool>(K, false), .scores = vector<int>(K, -1)});
    // 初始化id中的值
    for (int i = 0; i < MAX_USERS_NUM; ++i) {
        records[i].id = i;
    }

    // 读入满分
    for (int i = 0; i < K; ++i) {
        cin >> fullScore[i];
    }

    // 读取提交信息
    while (M--) {
        cin >> id >> problemId >> score;
        // 如果是一个更好的成绩，更新成绩信息表
        records[id].isSummit[problemId - 1] = true;
        if (score > records[id].scores[problemId - 1]) {
            records[id].scores[problemId - 1] = score;  // 他题目的序号从1开始排
        }
    }

    // 计算总成绩
    for (int i = 0; i < MAX_USERS_NUM; ++i) {
        // 成绩是否有效的临时变量
        bool isValid= false;
        // 总成绩的临时变量
        int total = 0;
        for (int j = 0; j < K; ++j) {
            if (records[i].scores[j] != -1){
                total += records[i].scores[j];
                isValid = true;
            }
        }

        if (isValid){
            records[i].total = total;
        } else{
            // 无效就是K个-1加起来，方便之后做比较
            records[i].total = -K;
        }
    }

    // 计算对的题目数的总数
    for (int i = 0; i < MAX_USERS_NUM; ++i) {
        records[i].perfectNum = inner_product(
                records[i].scores.begin(), records[i].scores.end(), fullScore.begin(), 0,
                std::plus<>(), std::equal_to<>()
        );
    }

    // 排序
    sort(records.begin(), records.end(), [](const auto &a, const auto &b) {
        if (a.total != b.total) return a.total > b.total;
        if (a.perfectNum != b.perfectNum) return a.perfectNum > b.perfectNum;
        return a.id < b.id;
    });

    // 纠正排名
    int rank = 0;
    int currentScore = INT32_MAX;
    for (int i = 0; i < MAX_USERS_NUM; ++i) {
        // 更新排名
        if (records[i].total < currentScore){
            rank = i + 1;
            currentScore = records[i].total;
        }

        records[i].rank = rank;
    }

    // 输出结果
    for (int i = 0; i < MAX_USERS_NUM; ++i) {

        // 如果从这个开始全是-1，那么结束输出
        if (records[i].total == -K)
            break;
        result << records[i].rank << " ";
        result << setw(5) << setfill('0') << records[i].id << " ";
        result << records[i].total << " ";
        for (int j = 0; j < K-1; ++j) {
            if (records[i].isSummit[j]){  // 如果提交过那么记录的成绩是0，反之是-
                if (records[i].scores[j] == -1){
                    result << "0" << " ";
                } else{
                    result << records[i].scores[j] << " ";
                }
            } else{
                result << "-" << " ";
            }

        }

        if (records[i].isSummit[K-1]){ // 如果提交过那么记录的成绩是0，反之是-
            if (records[i].scores[K-1] == -1){
                result <<  "0";
            } else{
                result << records[i].scores[K-1];
            }
        } else{
            result <<  "-";
        }


        result << endl;

    }

    cout << result.str();
    return 0;
}


TEST(TestCase, test_PTA_1075) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1075/data.json");
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

        PATJudge();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}