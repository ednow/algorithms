//
// Created by ednow on 2021/8/31.
//

#define CASEID 1033

#ifdef CASEID
#define MAIN PTA1033
#else
#define MAIN main
#endif

#include "set"
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct GasStation{
    // 距离出发点的距离
    int dis{};
    // 这个gasStation每单位油的价格
    double price{};
    // 这个gasStation的下标
    int idx{};
};

// 汽车自己的变量应该有一个struct管理
struct Car{
//    int maxDisWhenFull = gasCapacity*disPerGas;
//    // 现在走到的加油站的下标
//    int stationByNow{};
//    // 现在走的距离
//    int disByNow{};
//    // 现在tank中的油量
//    double gasByNow{};
};

int
MAIN(){
    // gasCapacity油箱的最大容量
    // destinationDis目的地的距离
    // disPerGas每单位油可以走的距离
    // StationNum加油站
    int gasCapacity{}, destinationDis{}, disPerGas{}, stationNum{};
    cin >> gasCapacity >> destinationDis >> disPerGas >> stationNum;
    // 加油站数据
    vector<GasStation> stations(stationNum);
    // 读取加油站数据
    for (int i = 0; i < stationNum; ++i) {
        cin >> stations[i].price;
        cin >> stations[i].dis;
        stations[i].idx = i;
    }
    sort(stations.begin(), stations.end(), [](auto &a, auto &b) {
        return a.dis < b.dis;
    });
    // 油满的时候走的最大距离
    int maxDisWhenFull = gasCapacity*disPerGas;
    // 现在走到的加油站的下标
    int stationByNow{};
    // 现在走的距离
    int disByNow{};
    // 现在tank中的油量
    double gasByNow{};
    // 现在花的钱
    double priceByNow{};
    while (stationByNow != stations.size() or disByNow < destinationDis) {
        // 这一站需要加的油量
        int gasToFill{};

        // 如果在这站加满能走到的最远距离
        int furthestStation{};
        for (int i = stationByNow+1; i < stationNum; ++i) {
            if (stations[i].dis <= stations[stationByNow].dis + maxDisWhenFull){
                furthestStation = i;
            } else{
                break;
            }
        }

        auto stationWithMinPrice = min_element(stations.begin()+stationByNow+1,stations.begin()+furthestStation+1, [](auto &a, auto &b) {
            return a.price < b.price;
        });
        auto stationWithLessPrice = find_if(stations.begin() + stationByNow + 1, stations.begin() + furthestStation + 1, [&](auto &a) {
            return a.price <= stations[stationByNow].price;
        });
        // 如果有更低的地方,加到能走到这个站的油量即可
        if (stationWithLessPrice != stations.end()) {
            gasToFill = (((*stationWithLessPrice).dis - stations[stationByNow].dis) * 1.0 / disPerGas) - gasByNow;
            stationByNow = (*stationWithLessPrice).idx;
        } else{
            // 如果高于现在的车站的价格,需要把油加满
            gasToFill = gasCapacity - gasByNow;
            // 车开往stationByNow
            stationByNow = (*stationWithMinPrice).idx;
        }
        // 更新总的花费
        priceByNow += gasToFill * 1.0 * (*stationWithMinPrice).price;
    }

    return 0;
}


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif