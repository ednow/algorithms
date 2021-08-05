//
// Created by ednow on 2021/8/5.
//

#include "TalentandVirtue.h"
#include "ios"
#include "iostream"
#include "iomanip"
#include "sstream"
#include "vector"
#include "algorithm"

using namespace std;


typedef struct record_ {
    int id;  // 序号
    int virtue;  // 美德值
    int talent;  // 才艺值
    int total; // 总分数
}record;

bool cmp(const record & a, const record & b){
    if (a.total != b.total) return a.total > b.total;
    if (a.virtue != b.virtue) return a.virtue > b.virtue;
    return a.id < b.id;
}


int TalentandVirtue(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    // N总共需要排序的数量,L最低分,H最高区间
    // sageNum：圣人数,nobleNum:君子数，foolNum:愚人数,smallNum：小人数
    int N{}, L{}, H{}, sageNum{}, nobleNum{}, foolNum{}, smallNum{}, id{}, virtue{}, talent{}, total{};
    ostringstream S;
    
    cin >> N >> L >> H;
    vector<record> sages(N);
    vector<record> nobles(N);
    vector<record> fools(N);
    vector<record> smalls(N);
    while (N--){
        cin >> id >> virtue >> talent;
        if (virtue < L || talent < L){  // 不满足条件
            continue;
        }

        total = virtue + talent;
        
        if ((virtue >= H) && (talent >= H)){ // 圣人
            sages[sageNum].virtue = virtue;
            sages[sageNum].id = id;
            sages[sageNum].talent = talent;
            sages[sageNum].total = total;
            sageNum++;
            continue;
        }

        if (virtue >= H){  // 君子
            nobles[nobleNum].virtue = virtue;
            nobles[nobleNum].id = id;
            nobles[nobleNum].talent = talent;
            nobles[nobleNum].total = total;
            nobleNum++;
            continue;
        }

        if (virtue >= talent){  // 愚人
            fools[foolNum].virtue = virtue;
            fools[foolNum].id = id;
            fools[foolNum].talent = talent;
            fools[foolNum].total = total;
            foolNum++;
            continue;
        }

        // 小人
        smalls[smallNum].virtue = virtue;
        smalls[smallNum].id = id;
        smalls[smallNum].talent = talent;
        smalls[smallNum].total = total;
        smallNum++;

    }

    sort(sages.begin(), sages.begin()+sageNum, cmp);
    sort(nobles.begin(), nobles.begin()+nobleNum, cmp);
    sort(fools.begin(), fools.begin()+foolNum, cmp);
    sort(smalls.begin(), smalls.begin()+smallNum, cmp);

    S << (sageNum + nobleNum + foolNum + smallNum) << endl;
    for (int i = 0; i < sageNum; ++i) {
        S << setw(8) << setfill('0') << sages[i].id << " ";
        S << sages[i].virtue << " " << sages[i].talent << endl;
    }

    for (int i = 0; i < nobleNum; ++i) {
        S << setw(8) << setfill('0') << nobles[i].id << " ";
        S << nobles[i].virtue << " " << nobles[i].talent << endl;
    }

    for (int i = 0; i < foolNum; ++i) {
        S << setw(8) << setfill('0') << fools[i].id << " ";
        S << fools[i].virtue << " " << fools[i].talent << endl;
    }

    for (int i = 0; i < smallNum; ++i) {
        S << setw(8) << setfill('0') << smalls[i].id << " ";
        S << smalls[i].virtue << " " << smalls[i].talent << endl;
    }

    cout << S.str();

    return 0;
}

TEST(TestCase, test_PTA_1062) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1062/data.json");
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

        TalentandVirtue();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}