// P3372 【模板】线段树 1 —— 区间修改 + 区间查询（懒标记 lazy）
// 2026-08-24 本地对拍 1000 组通过 | 数据结构 | 线段树第三档（build+query+lazy 全手写）
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,M;
struct Node{
   ll data;
   int lazy=0;
};
vector<Node>tree;
vector<ll>a;
void build(int node,int l,int r){
    if(l==r){
        tree[node].data=a[l];return ;
    }
    int mid=l+(r-l)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node].data=tree[node*2].data+tree[node*2+1].data;
}
// lazy 下沉:把 node 欠的账还给孩子(孩子 data += lazy×自己长度,孩子 lazy +=,自己清 0)
void pushDown(int node,int l,int r){
    if(tree[node].lazy!=0){
        int mid=l+(r-l)/2;
        tree[node*2].data+=tree[node].lazy*(mid-l+1);
        tree[node*2+1].data+=tree[node].lazy*(r-mid);
        tree[node*2].lazy+=tree[node].lazy;
        tree[node*2+1].lazy+=tree[node].lazy;
        tree[node].lazy=0;
    }
}
void update(int node,int l,int r,int ql,int qr,ll k){
    if(qr<l||ql>r)return ;
    if(ql<=l&&qr>=r){                       // 整块覆盖 → 记账,不动子孙
        tree[node].data+=k*(r-l+1);
        tree[node].lazy+=k;
        return ;
    }
    int mid=l+(r-l)/2;
    pushDown(node,l,r);                     // 劈两半之前必须先把欠账还了
    update(node*2,l,mid,ql,qr,k);
    update(node*2+1,mid+1,r,ql,qr,k);
    tree[node].data=tree[node*2].data+tree[node*2+1].data;   // 回来修自己
}
long long query(int node,int l,int r,int ql,int qr){
    if(ql>r||qr<l){
        return 0;
    }
    if(ql<=l&&qr>=r)return tree[node].data;
    int mid=l+(r-l)/2;
    pushDown(node,l,r);                     // query 劈之前也要还账
    return query(node*2,l,mid,ql,qr)+query(node*2+1,mid+1,r,ql,qr);
}
int main(){
    cin>>N>>M;
    tree.resize(4*N+1);
    a.resize(N+1);
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    build(1,1,N);
    while(M--){
        int op;cin>>op;
        if(op==2){
            int x,y;cin>>x>>y;
            cout<<query(1,1,N,x,y)<<endl;
        }
        else {
            int x,y;ll k;cin>>x>>y>>k;
            update(1,1,N,x,y,k);
        }
    }
    return 0;
}
