// P3368 【模板】树状数组 2 —— 区间修改 + 单点查询（差分法）
// 2026-08-23 本地样例验证通过 | 数据结构 | 树状数组第二档
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,M;
vector<ll>b;          // b 里存的是【差分】d，不是原数组 a！

ll lowbit(int x){
    return x&(-x);
}

void add(int p,ll k){         // 单点加（作用于差分）
    while(p<=N){
        b[p]+=k;
        p+=lowbit(p);
    }
}

ll count(int p){              // 前缀和（作用于差分）= 还原原数组前缀
    ll res=0;
    while(p){
        res+=b[p];
        p-=lowbit(p);
    }
    return res;
}

int main(){
    cin>>N>>M;
    b.resize(N+1);
    b[0]=0;

    vector<ll>a(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>a[i];
        b[i]=a[i]-a[i-1];     // 建差分 d[i]=a[i]-a[i-1]，d[1]=a[1]
    }
    // O(n) 建树：把差分塞进树状数组（推给父亲）
    for(int i=1;i<=N;i++){
        int j=i+lowbit(i);
        if(j<=N)b[j]+=b[i];
    }

    while(M--){
        char op;
        cin>>op;
        if(op=='1'){          // 1 x y k：区间[x,y]全加k → 差分只动两个点
            int x,y;ll k;
            cin>>x>>y>>k;
            add(x,k);         // d[x] += k
            add(y+1,-k);      // d[y+1] -= k（y+1>N 时 while 自动跳过，安全）
        }
        else {                // 2 x：输出第 x 个数 = d 的前缀和
            int p;
            cin>>p;
            cout<<count(p)<<endl;
        }
    }
    return 0;
}
