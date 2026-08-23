// P3374 【模板】树状数组 1 —— 单点修改 + 区间查询
// 2026-08-23 AC | 数据结构 | 第一道树状数组
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> b;        // b[i] = 以 i 结尾、长度 = lowbit(i) 的区间的和（块和）
int N;               // 数组长度（1-indexed）

// 取出 x 最低位 1 的权值（树状数组的魔法函数）
ll lowbit(int x){
    return x&(-x);
}

// 单点修改：a[p] 加 k → 所有"管到 p"的块都加 k（沿着 p += lowbit(p) 往上跳）
void add(ll p,ll k){
    while(p<=N){
        b[p]+=k;
        p+=lowbit(p);
    }
}

// 前缀和：sum a[1..p] → 拆成二进制块，沿 p -= lowbit(p) 往下跳
ll count(int p){
    ll res=0;
    while(p){
        res+=b[p];
        p-=lowbit(p);
    }
    return res;
}

int main(){
    cin>>N;
    b.resize(N+1);
    b[0]=0;

    int m;cin>>m;
    for(int i=1;i<=N;i++){
        cin>>b[i];                     // 先塞原始值
    }
    // O(n) 建树：每个节点 i 的父亲是 i+lowbit(i)，把值往上推给父亲一次
    for(int i=1;i<=N;i++){
        int j=i+lowbit(i);
        if(j<=N)b[j]+=b[i];
    }

    while(m--){
        char op;                       // 这题 op 只有 1/2 一位数，能过；通用写法是 int op
        cin>>op;
        if(op=='1'){                   // 1 x k：第 x 个数加 k
            int p;ll k;
            cin>>p>>k;
            add(p,k);
        }
        else {                         // 2 x y：输出区间 [x,y] 的和
            int x,y;
            cin>>x>>y;
            cout<<count(y)-count(x-1)<<endl;
        }
    }
    return 0;
}
