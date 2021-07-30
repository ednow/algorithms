//
// Created by ednow on 2021/7/30.
//

#include "ListSorting.h"

#include "iomanip"
#include "vector"
#include "iostream"
#include "ios"
#include "string"
#include "algorithm"


using namespace std;

typedef struct record_{
    int ID;
    string name;
    int score;
}record;

int ListSorting(){
//    ios::sync_with_stdio(false);
    int N{}, C{}, ID{}, score{};
    string name;
    cin >> N >> C;
    vector<record> records(N);
    for (int i = 0; i < N; ++i) {
        cin >> ID >> name >> score;
        records[i].score = score;
        records[i].ID = ID;
        records[i].name = name;
    }

    switch (C) {
        case 1:
            sort(records.begin(), records.end(), [](const auto &a, const auto &b) { return a.ID < b.ID; });
            break;
        case 2:
            sort(records.begin(), records.end(), [](const auto &a, const auto &b) {
                if(a.name != b.name)  return a.name < b.name;
                return a.ID < b.ID;
            });
            break;
        case 3:
            sort(records.begin(), records.end(), [](const auto &a, const auto &b) {
                if(a.score != b.score)  return a.score < b.score;
                return a.ID < b.ID;
            });
            break;
        default:
            break;
    }

    ostringstream S;
    for(const auto & one: records){
        S << setfill('0') << setw(6) << one.ID << " ";
        S << one.name << " ";
        S << one.score << endl;
    }

    cout << S.str();

    return 0;
}


TEST(TestCase, test_PTA_1028) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1028/data.json");
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

        ListSorting();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}