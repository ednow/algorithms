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
#include "iomanip"

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
    if (stationNum==0){
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    // 加油站数据
    vector<GasStation> stations(stationNum);
    // 读取加油站数据
    for (int i = 0; i < stationNum; ++i) {
        cin >> stations[i].price;
        cin >> stations[i].dis;
    }
    sort(stations.begin(), stations.end(), [](auto &a, auto &b) {
        return a.dis < b.dis;
    });
    if (stations[0].dis > 0) {
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    // 应排序之后再标号
    for (int i = 0; i < stationNum; ++i) {
        stations[i].idx = i;
    }
    // 补一个终点站虚拟站
    // 这里需要提防，他本来就在终点站设置了一个加油站
    auto dest = find_if(stations.begin(), stations.end(), [&](auto &a) {
        return a.dis == destinationDis;
    });
    if (dest != stations.end()) {
        (*dest).price = -1;
    }else{
        stations.push_back(GasStation{.dis=destinationDis, .price=-1, .idx=stationNum});
    }

    // 油满的时候走的最大距离
    int maxDisWhenFull = gasCapacity*disPerGas;
    // 现在走到的加油站的下标
    int stationByNow{};
    // 按照现在油桶里的油还能走的距离
    double disToGo{};
    // 现在走的距离
    int disByNow{};
    // 现在花的钱
    double priceByNow{};  
    // 是否能走到终点站
    bool isFinish{true};
    while (stationByNow != stations.size() -1) {
        bool isFindNext = false;
        // 如果在这站加满能走到的最远距离
        int furthestStation{};
        for (int i = stationByNow+1; i < stationNum+1; ++i) {
            if (stations[i].dis <= stations[stationByNow].dis + maxDisWhenFull){
                furthestStation = i;
                isFindNext = true;
            } else{
                break;
            }
        }
        // 走不到下一个站点就结束了
        // isFindNext和isFinish可以是同一个变量，但会导致语义性不强
        if (!isFindNext) {
            isFinish = false;
            break;
        }

        // 后面能到达的车站,车站之间最小的价格
        auto stationWithMinPrice = min_element(stations.begin()+stationByNow+1,stations.begin()+furthestStation+1, [](auto &a, auto &b) {
            return a.price < b.price;
        });
        // 后面能到达的车站,存在比当前车站更低价格的车站
        auto stationWithLessPrice = find_if(stations.begin() + stationByNow + 1, stations.begin() + furthestStation + 1, [&](auto &a) {
            return a.price <= stations[stationByNow].price;
        });
        // 如果有更低的地方,加到能走到这个站的油量即可
        if (stationWithLessPrice != stations.begin() + furthestStation + 1) {
            // 扣费
            priceByNow += stations[stationByNow].price * ((*stationWithLessPrice).dis - stations[stationByNow].dis - disToGo);
            // 加油
            disToGo+=(*stationWithLessPrice).dis - stations[stationByNow].dis-disToGo;
            // 耗油
            disToGo -= (*stationWithLessPrice).dis - stations[stationByNow].dis;
            // 更新里程
            disByNow += (*stationWithLessPrice).dis - stations[stationByNow].dis;
            // 驶达下一站
            stationByNow = (*stationWithLessPrice).idx;
        } else{
            // 如果高于现在的车站的价格,需要把油加满
            // 扣费
            priceByNow+=stations[stationByNow].price * (maxDisWhenFull-disToGo);
            // 加油
            disToGo=maxDisWhenFull;
            // 耗油
            disToGo -= (*stationWithMinPrice).dis - stations[stationByNow].dis;
            // 里程更新
            disByNow+=((*stationWithMinPrice).dis - stations[stationByNow].dis);
            // 驶达下一站
            stationByNow = (*stationWithMinPrice).idx;
        }
    }

    if (isFinish) {
        cout << setprecision(2) << fixed << priceByNow/disPerGas;
    } else {
        cout << "The maximum travel distance = " << setprecision(2) << fixed << (disByNow+maxDisWhenFull-disToGo)*1.0;
    }

    return 0;
}


#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif