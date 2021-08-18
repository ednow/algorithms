//
// Created by ednow on 2021/8/18.
//

// 来源
// https://blog.csdn.net/AAmiu/article/details/110009838

// 上交的时候将这一行注释掉即可
#define CASEID  1135

#ifdef CASEID
#define MAIN PTA1135
#else
#define MAIN main
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef struct Tnode *p;
const int N=55;
struct Tnode{
    p ls,rs;
    int data;
};
p root;
int n,preindex,preorder[N],inorder[N],a[N],b[N];
bool vis[10005];
void init(){
    root=NULL;
    memset(vis,0,sizeof(vis));
    preindex=0;
}
int find(int begin,int end,int val){
    for(int i=begin;i<=end;i++){
        if(inorder[i]==val)	return i;
    }
    return -1;
}
p buildtreechild(int begin,int end){
    if(begin>end)	return NULL;
    p root=new Tnode;
    root->data=preorder[preindex];
    int index=find(begin,end,preorder[preindex]);
    if(index==-1)	return NULL;
    preindex++;
    root->ls=buildtreechild(begin,index-1);
    root->rs=buildtreechild(index+1,end);
    return root;
}
p buildtree(){
    if(preorder==NULL||inorder==NULL)	return NULL;
    return buildtreechild(0,n-1);
}
bool check1(p u){
    if(u==NULL)	return true;
    if(vis[u->data]){
        if(u->ls&&vis[u->ls->data])	return false;
        if(u->rs&&vis[u->rs->data])	return false;
    }
    return check1(u->ls)&&check1(u->rs);
}
int depth(p u){
    if(u==NULL)	return 0;
    int left=depth(u->ls);
    int right=depth(u->rs);
    if(vis[u->data])	return max(left,right);
    return max(left,right)+1;
}
bool check2(p u){
    if(u==NULL)	return true;
    int left=depth(u->ls);
    int right=depth(u->rs);
    if(left!=right)	return false;
    return check2(u->ls)&&check2(u->rs);
}
int MAIN(){
    int t;
//    scanf("%d",&t);
    cin >> t;
    while(t--){
        init();
//        scanf("%d",&n);
        cin >> n;

        for(int i=0;i<n;i++){
//            scanf("%d",&a[i]);
            cin >> a[i];
            if(a[i]<0)	preorder[i]=-a[i],vis[abs(a[i])]=true;
            else	preorder[i]=a[i];
            b[i]=abs(a[i]);
        }
        sort(b,b+n);
        for(int i=0;i<n;i++)	inorder[i]=b[i];
        root=buildtree();
        if(a[0]<0||!check1(root)||!check2(root))	cout << "No\n";
        else	cout << "Yes\n";
    }
    return 0;
}
#ifdef CASEID
#include "utils.h"
TEST(PTA, CASEID){
    DO_TEST(CASEID)
}
#endif