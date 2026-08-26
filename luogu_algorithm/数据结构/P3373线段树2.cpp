// P3373 【模板】线段树 2 —— 双 lazy(乘 + 加),区间乘、区间加、区间求和 mod p
// 2026-08-25 用户从零手写 | 本地样例 17/2 过 + 暴力对拍 2000 组全过 | 数据结构 | 线段树收官(第四档)
// 核心:把累计操作统一成 x -> x*mul + add;乘法档会"污染"加法档 add*=k;pushDown 先乘后加
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,p;
vector<ll>a;
struct Node{
    ll mul=1;
    ll add=0;
    ll data;
};
vector<Node>tree;
void build(int node,int l,int r){
    if(l==r){tree[node].data=a[l]%p;return ;}
    int mid=l+(r-l)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node].data=(tree[node*2].data+tree[node*2+1].data)%p;
}
// 先乘后加:mul 块把孩子的 data/mul/add 全乘一遍,add 块再把 node.add 加下去
void pushDown(int node,int l,int r){
    if(tree[node].mul==1&&tree[node].add==0)return ;
    int mid=l+(r-l)/2;
    if(tree[node].mul!=1){
        tree[node*2].data=tree[node*2].data*tree[node].mul%p;
        tree[node*2+1].data=tree[node*2+1].data*tree[node].mul%p;
        tree[node*2].mul=tree[node*2].mul*tree[node].mul%p;
        tree[node*2+1].mul=tree[node*2+1].mul*tree[node].mul%p;
        tree[node*2].add=tree[node*2].add*tree[node].mul%p;      // add 标记也要被乘!乘法污染加法
        tree[node*2+1].add=tree[node*2+1].add*tree[node].mul%p;
        tree[node].mul=1;
    }
    if(tree[node].add!=0){
        tree[node*2].data   = (tree[node*2].data   + tree[node].add*(mid-l+1)) % p;
        tree[node*2+1].data = (tree[node*2+1].data + tree[node].add*(r-mid))% p;
        tree[node*2].add    = (tree[node*2].add    + tree[node].add)% p;
        tree[node*2+1].add  = (tree[node*2+1].add  + tree[node].add)% p;
        tree[node].add=0;
    }
}
void update_mul(int node,int l,int r,int ql,int qr,ll mul){
    if(qr<l||ql>r)return;
    if(ql<=l&&qr>=r){
        tree[node].data=tree[node].data*mul%p;
        tree[node].mul=tree[node].mul*mul%p;
        tree[node].add=tree[node].add*mul%p;    // ← 整块乘法最关键的污染行
        return;
    }
    int mid=l+(r-l)/2;
    pushDown(node,l,r);
    update_mul(node*2,l,mid,ql,qr,mul);
    update_mul(node*2+1,mid+1,r,ql,qr,mul);
    tree[node].data=(tree[node*2].data+tree[node*2+1].data)%p;
}
void update_add(int node,int l,int r,int ql,int qr,ll k){
     if(qr<l||ql>r)return;
    if(ql<=l&&qr>=r){
        tree[node].data=(tree[node].data+k*(r-l+1))%p;
        tree[node].add=(tree[node].add+k)%p;
        return;
    }
    int mid=l+(r-l)/2;
    pushDown(node,l,r);
    update_add(node*2,l,mid,ql,qr,k);
    update_add(node*2+1,mid+1,r,ql,qr,k);
    tree[node].data=(tree[node*2].data+tree[node*2+1].data)%p;
}
ll query(int node,int l,int r,int ql,int qr){
    if(ql>r||qr<l)return 0;
    if(ql<=l&&qr>=r){ return tree[node].data; }
    int mid=l+(r-l)/2;
    pushDown(node,l,r);
    ll left=query(node*2,l,mid,ql,qr);
    ll right=query(node*2+1,mid+1,r,ql,qr);
    return (left+right)%p;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);   // 1e5 次操作,不加可能 TLE
    cin >> n >> m >> p;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    tree.resize(4*n+1);
    build(1,1,n);
    while(m--){
        int op,x,y; cin >> op >> x >> y;
        if(op==1){ ll k; cin >> k; update_mul(1,1,n,x,y,k); }
        else if(op==2){ ll k; cin >> k; update_add(1,1,n,x,y,k); }
        else cout << query(1,1,n,x,y) << '\n';
    }
    return 0;
}
