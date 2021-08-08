//
// Created by ednow on 2021/8/7.
//

#include "PATRankingOfInstitutions.h"
#include "ios"
#include "iostream"
#include "sstream"
#include "map"
#include "vector"
#include "cctype" // to_lower
#include "algorithm"
#include "limits"

using namespace std;

typedef struct teamInfo_ {
    int TWS{};  // 加权总分，排序的时候才计算
    int scoreT{};  // 顶级得分
    int scoreA{}; // 甲级得分
    int scoreB{}; // 乙级得分
    int Ns{};  // 提交的题目总数
    string code; // 转为vector的时候才赋值
    int rank{}; // 排名，更新排名的时候哦才赋值
}teamInfo;

int PATRankingOfInstitutions(){
//    加快读取的速度
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    // N总的提交数,score临时变量某道题的得分,TWS临时变量
    int N{}, score{};
    // submissionId这道题的提交代号，code学校代码
    string submissionId, code;
    // 拼接输出
    ostringstream result;
    // 每一所学校的信息表
    map<string, teamInfo> teams;

    cin >> N;
    while (N--){
        cin >> submissionId >> score >> code;
        // 将学校代号转为小写
        transform(code.begin(), code.end(), code.begin(), [](const auto &a) { return tolower(a); });
        teams[code].Ns++;
        switch (submissionId.at(0)) {
            case 'T':
                teams[code].scoreT += score;
                break;
            case 'A':
                teams[code].scoreA += score;
                break;
            case 'B':
                teams[code].scoreB += score;
                break;
            default:
                break;
        }
    }

    vector<teamInfo> teamsVector;
    // 将map转为vector,并计算总分
    for (auto &a: teams) {
        a.second.code = a.first;
        a.second.TWS = (int) (a.second.scoreT * 1.5 + a.second.scoreA + a.second.scoreB / 1.5);
        teamsVector.push_back(a.second);
    }

    // 排序
    sort(teamsVector.begin(), teamsVector.end(), [](const auto &a,const auto &b){
        if (a.TWS != b.TWS) return a.TWS > b.TWS;
        if (a.Ns != b.Ns) return a.Ns < b.Ns;
        return a.code < b.code;
    });

    // 纠正排名
    int rank = 0;
    score = INT32_MAX;
    for (int i = 0; i < teamsVector.size(); ++i) {
        if (teamsVector[i].TWS < score){
            score = teamsVector[i].TWS;
            rank = i+1;
        }
        teamsVector[i].rank = rank;
    }
    result << teamsVector.size() << endl;
    for (const auto &a: teamsVector) {
        result << a.rank << " " << a.code << " " << a.TWS << " " << a.Ns << endl;
    }

    cout << result.str();
    return 0;
}


TEST(TestCase, test_PTA_1141) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1141/data.json");
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

        PATRankingOfInstitutions();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}