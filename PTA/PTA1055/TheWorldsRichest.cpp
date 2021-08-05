//
// Created by ednow on 2021/8/5.
//

#include "TheWorldsRichest.h"

#include "vector"
#include "algorithm"  // copy_if,sort，min
#include "iostream"  // cin、cout
#include "string"
#include "ios"   // 禁止同步scanf
#include "iterator" // back_inserter

using namespace std;


typedef struct record_{
    string name;
    int age;
    int worth;
}record;



int TheWorldsRichest(){
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr); cout.tie(nullptr);
    // N一共有多少人.K请求的个数,age、worth读入数据的时候的临时变量
    // maxLen需要求的前几名, minAge满足要求的最小的年龄, 满足要求的最大的年龄
    // exactLen实际输出的长度
    int N{}, K{}, age, worth, maxLen, minAge, maxAge, exactLen;
    bool find = false;
    // name读入数据的时候的临时变量
    string name;
    cin >> N >> K;
    // temp 处理的时候的临时变量
    vector<record> records(N);
    // 最后输出的字符串
    string result;

    // 读入记录
    for (int i = 0; i < N; ++i) {
        cin >> records[i].name >> records[i].age >> records[i].worth;
    }

    sort(records.begin(), records.end(), [](const auto & a, const auto & b){
        if(a.worth != b.worth)  return a.worth > b.worth;
        if (a.age != b.age) return a.age < b.age;
        return a.name < b.name;
    });

    for (int i = 1; i < K+1; ++i) {
        cin >> maxLen >> minAge >> maxAge;
        // 筛选出相应年龄段的人
        // 再根据净利润降序排序

        int num = 0;
        result += "Case #" + to_string(i) + ":\n";
        for (int j = 0; j < N; ++j) {
            if ((records[j].age >= minAge) && (records[j].age <= maxAge)){
                result += records[j].name + " " + to_string(records[j].age) + " " + to_string(records[j].worth) + '\n';
                num++;
            }
            if(num==maxLen){
                break;
            }
        }

        if (!num){
            result += "None\n";
        }
    }

    cout << result;

    return 0;
}


TEST(TestCase, test_PTA_1055) {
    using json = nlohmann::json;
    json j, config;
    ifstream in("../PTA/PTA1055/data.json");
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

        TheWorldsRichest();
        ASSERT_EQ(testcase["answer"], redirectStream.str());
        std::cout.rdbuf(oldbuf);

        cout << "testCaseId:" << testcase["id"] << " passed" << endl;
        cout << "--------------------------------" << endl;
    }
}