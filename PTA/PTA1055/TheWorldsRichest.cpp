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
    // N一共有多少人.K请求的个数,age、worth读入数据的时候的临时变量
    // maxLen需要求的前几名, minAge满足要求的最小的年龄, 满足要求的最大的年龄
    // exactLen实际输出的长度
    int N{}, K{}, age, worth, maxLen, minAge, maxAge, exactLen;
    // name读入数据的时候的临时变量
    string name;
    cin >> N >> K;
    // temp 处理的时候的临时变量
    vector<record> records(N), temp;
    // 最后输出的字符串
    string result;

    // 读入记录
    while (N--){
        cin >> name >> age >> worth;
        records[N].age = age;
        records[N].name = name;
        records[N].worth = worth;
    }

    for (int i = 1; i < K+1; ++i) {
        cin >> maxLen >> minAge >> maxAge;
        // 筛选出相应年龄段的人
        copy_if(records.begin(), records.end(), back_inserter(temp), [&](const auto & a){
            return (a.age >= minAge) && (a.age <= maxAge);
        });

        // 先根据年龄和姓名非降序排序
        sort(temp.begin(), temp.end(), [](const auto & a, const auto & b){
            if (a.age != b.age) return a.age < b.age;
            return a.name < b.name;
        });

        // 再根据净利润降序排序
        sort(temp.begin(), temp.end(), [](const auto & a, const auto & b){
            return a.worth > b.worth;
        });

        result += "Case #" + to_string(i) + ":\n";
        if (!temp.empty()){  // 如果存在记录
            exactLen = min(maxLen, (int) temp.size());
            for (int j = 0; j < exactLen; ++j) {
                result += temp[j].name + " " + to_string(temp[j].age) + " " + to_string(temp[j].worth) + '\n';
            }
        } else{
            result += "None\n";
        }

        temp.clear();
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