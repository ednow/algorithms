#include <iostream>
#include <cstring>
#include <cstdio>
#include<algorithm>
#include <cmath>
#include<queue>
#include<map>
#include<stack>
#include<sstream>

// from https://blog.csdn.net/sunshine_critical/article/details/84940105

#define CASEID 1103

#ifdef CASEID
#define MAIN PTA111111
#else
#define MAIN main
#endif

using namespace std;
const int maxn = 1e5+7;
vector<int>v,ansque,tempque;
int n,k,p,maxque = -1;
bool exist = false;

int pows(int x, int y)
{
    int ans = 1;
    while(y>0)
    {

        if(y%2)
        {
            ans *= x;
        }
        x *= x;
        y >>= 1;
    }
    return ans;
}

void dfs(int index, int K, int sum, int que)
{
    //cout <<"index: " << index <<" K "<< K << " sum "<< sum << " que: "<< que << endl;
    if(K == k)
    {
        if(maxque < que && sum == n)
        {
            maxque = que;
            ansque = tempque;
            exist = true;
        }
        return;
    }
    for(int i = index; i > 0; i --)
    {
        //cout << i << " v[i]: " << v[i] << " sum: " << sum << endl;
        if(sum + v[i] <= n)
        {
            //cout << "zx" << endl;
            tempque[K] = i;
            dfs(i, K+1, sum+v[i],que+i);
        }
        //cout << i << " " << sum << endl;
    }
}

int MAIN()
{
    cin >> n >> k >> p;
    int index = 1,temp = 0;
    while(temp <= n)
    {
        v.push_back(temp);
        temp = pows(index,p);
        index ++;
        //cout <<v[index-2] <<endl;
    }
    tempque.resize(k);
    dfs(index-2,0,0,0);
    if(exist)
    {
        cout << n << " = " << ansque[0] << "^" << p;
        for(int i = 1; i < k; i ++)
        {
            cout << " + " << ansque[i] << "^" << p;
        }
        cout << endl;

    }
    else
        cout << "Impossible" <<endl;
    return 0;
}

//#ifdef CASEID
//#include "utils.h"
//TEST(OTHER, CASEID){
//    DO_TEST(CASEID)
//}
//#endif