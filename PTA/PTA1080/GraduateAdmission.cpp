//
// Created by ednow on 2021/8/7.
//

#include "GraduateAdmission.h"

#include "iostream"
#include "vector"
#include "sstream"
#include "algorithm"  // transform
#include "ios"
#include "limits"
#include "queue"
#include "functional" // std:: minus



using namespace std;

typedef struct application_ {
    int id{}; // 记录下这个申请表的id
    int entry{}; // 笔试成绩
    int interview{}; // 面试成绩
    int final{}; // 最终成绩=(笔试成绩 + 面试成绩)/2
    vector<int> preference; // 志愿
    int rank{};  // 排名
}application;

int GraduateAdmission(){
//    加快读入的速度
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    ostringstream result;

    // N研究生申请书份数,M研究生学校总数，K每个人的志愿数
    int N{},M{},K{};

    cin >> N >> M >> K;

    // applications申请书表
    vector<application> applications(N, application{.preference = vector<int>(K)});
    // 初始化每份申请书的id
    for (int i = 0; i < N; ++i) {
        applications[i].id = i;
    }

    // 每个学校的研究生人数配额，下标为学校编号
    vector<int> quotas(M);
    // 每个学校接受的申请人，下标为学校编号，值为申请人列表
    vector<vector<int>> acceptances(M);

    // 读入每个学校的配额
    for (int i = 0; i < M; ++i) {
        cin >> quotas[i];
    }

    // 读入每份申请书
    for (int i = 0; i < N; ++i) {
        cin >> applications[i].entry >> applications[i].interview;

        // 计算最终成绩,这里可不可以不/2啊，感觉除不除都一样，除了反而效率会低
//        applications[i].final = (applications[i].entry + applications[i].interview) / 2;
        applications[i].final = applications[i].entry + applications[i].interview;

        // 读入志愿
        for (int j = 0; j < K; ++j) {
            cin >> applications[i].preference[j];
        }
    }

    // 按照总成绩和笔试成绩分别排序
    sort(applications.begin(), applications.end(), [](const auto &a, const auto &b) {
        if (a.final != b.final) return a.final > b.final;
        return a.entry > b.entry;
    });

    // 修正排名
    int currentFinal = INT32_MAX;
    int currentEntry = INT32_MAX;
    int currentRank = 0;
    for (int i = 0; i < N; ++i) {

        // 总成绩不相同排名不相同
        if (applications[i].final < currentFinal){
            currentRank++;
            currentFinal = applications[i].final;
            currentEntry = applications[i].entry;
        } else{
            // 总成绩相同，按照笔试成绩给排名
            if (applications[i].final == currentFinal && applications[i].entry < currentEntry){
                currentRank++;
                currentEntry = applications[i].entry;
            }
        }
        applications[i].rank = currentRank;
    }

    // 处理申请
    currentRank = 1;
    // 处理队列
    queue<application> q;
    application head;
    vector<int> newAcceptances(M, 0);
    for (int i = 0; i < N; ++i) {  // 处理每一份申请
        if (currentRank == applications[i].rank){
            q.push(applications[i]);  // 处于同一个排名，压入队列等待处理
            continue;
        }

        // 同一个排名的请求都已经压入
        // 处理队列中的请求
        while (!q.empty()){
            head = q.front();
            // 查看这个人的志愿下还有没有配额
            for (int j = 0; j < K; ++j) {

                // 有余额
                if (quotas[head.preference[j]] > 0){
                    // 该学校新接收的人数加1
                    newAcceptances[head.preference[j]]++;
                    acceptances[head.preference[j]].push_back(head.id);
                    break;
                }
            }

            q.pop();
        }

        // 更新配额
        transform(quotas.begin(), quotas.end(), newAcceptances.begin(), quotas.begin(), minus<>());
        // 重置每个学校新接收的人数
        newAcceptances.assign(M, 0);
        // 压入此时的学生申请表
        q.push(applications[i]);
        currentRank = applications[i].rank;
    }

    // 处理尾巴
    // 处理队列中的请求
    while (!q.empty()){
        head = q.front();
        // 查看这个人的志愿下还有没有配额
        for (int j = 0; j < K; ++j) {

            // 有余额
            if (quotas[head.preference[j]] > 0){
                // 该学校新接收的人数加1
                newAcceptances[head.preference[j]]++;
                acceptances[head.preference[j]].push_back(head.id);
                break;
            }
        }
        q.pop();
    }


    // 每个学校的新生按照id升序排好,并输出
    for (int i = 0; i < M; ++i) {
        // 如果这个学校没有新生输出为空
        if (acceptances[i].empty()){
            result << endl;
            continue;
        }

        // 否则排序输出
        sort(acceptances[i].begin(), acceptances[i].end());

        for (int j = 0; j < acceptances[i].size() - 1 && !acceptances[i].empty(); ++j) {
            result << acceptances[i][j] << " ";
        }

        result << acceptances[i][acceptances[i].size() - 1] << endl;


    }

    cout << result.str();

    return 0;
}


TEST(TestCase, test_PTA_1080) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1080/data.json");
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

        GraduateAdmission();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}