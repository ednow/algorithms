//
// Created by ednow on 2021/9/2.
//

#define CASEID 1153

#ifdef CASEID
#define MAIN PTA1153
#else
#define MAIN main
#endif

#include "iostream"
#include "map"
#include "vector"
#include "algorithm"
#include "iomanip"
#include "ios"
#include "sstream"

using namespace std;

struct Site{
    int siteId{};
    int testNum{};
    int totalScore{};
};

struct Card{
    string card{};
    int score{};
};

int
MAIN(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ostringstream resultStr;
    int queryNum{}, cardNum{};
    cin >> cardNum >> queryNum;
    map<char, vector<Card>> cardsByLevel;
    map<int, map<int, int>> testNumByDateAndSite;
    map<int, Site> numAndTotalScoreBySiteId;
    while (cardNum--) {
        string card{};
        int score{};
        cin >> card >> score;
        int siteId{},date{},testId{};
        sscanf(card.substr(1,card.size()-1).c_str(), "%3d%6d%3d", &siteId, &date, &testId);
        cardsByLevel[card[0]].push_back(Card{.card=card, .score=score});
        testNumByDateAndSite[date][siteId]++;
        numAndTotalScoreBySiteId[siteId].testNum++;
        numAndTotalScoreBySiteId[siteId].totalScore+=score;
    }
    map<int, vector<Site>> siteByDate;
    for (auto &numByDateAndSite:testNumByDateAndSite) {
        for (auto &numBySite:numByDateAndSite.second) {
            siteByDate[numByDateAndSite.first].push_back(Site{.siteId=numBySite.first, .testNum=numBySite.second});
        }
    }
    for (auto&item:cardsByLevel) {
        sort(item.second.begin(), item.second.end(), [](const auto &a, const auto &b) {
            if (a.score != b.score) return a.score > b.score;
            return a.card < b.card;
        });
    }

    for (auto&item:siteByDate) {
        sort(item.second.begin(), item.second.end(), [](const auto &a, const auto &b) {
            if (a.testNum != b.testNum) return a.testNum > b.testNum;
            return a.siteId < b.siteId;
        });
    }

    for (int i = 1; i < queryNum+1; ++i) {
        int queryType;
        cin >> queryType;
        // 输出对应等级的结果
        if (queryType == 1) {
            string level;
            cin >> level;
            resultStr << "Case " << i << ": " << queryType << " " << level<< endl;
            if (cardsByLevel.find(level[0]) == cardsByLevel.end()) {
                resultStr << "NA"<<endl;
                continue;
            }
            for (auto & item:cardsByLevel[level[0]]) {
                resultStr << item.card << " " <<item.score << endl;
            }
            continue;
        }
        // 输出每一个考试站的情况
        if (queryType == 2) {
            int siteId;
            cin >> siteId;
            resultStr << "Case " << i << ": " << queryType << " " << setw(3) << setfill('0') << siteId<< endl;
            if (numAndTotalScoreBySiteId.find(siteId)==numAndTotalScoreBySiteId.end()) {
                resultStr << "NA"<<endl;
                continue;
            }
            resultStr << numAndTotalScoreBySiteId[siteId].testNum << " "
            <<  numAndTotalScoreBySiteId[siteId].totalScore << endl;
            continue;
        }
        // 输出每一个日期中，考试站和他提交的题目的数量
        if (queryType==3) {
            int date;
            cin >> date;
            resultStr << "Case " << i << ": " << queryType << " " << setw(6) << setfill('0') << date<< endl;
            if (siteByDate.find(date)==siteByDate.end()) {
                resultStr << "NA"<<endl;
                continue;
            }
            for (auto & item:siteByDate[date]) {
                resultStr << setw(3) << setfill('0') << item.siteId << " "
                    << item.testNum << endl;
            }
        }

    }
    cout << resultStr.str();
    return 0;
}


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif