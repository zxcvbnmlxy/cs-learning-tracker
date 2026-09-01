//P3811 【模板】模意义下的乘法逆元
//求 1~n 所有数 mod p 的逆元 (p 为质数, n<p, n≤3e6), 输出 n 行
//线性递推: p = (p/i)·i + (p%i) → 模 p 得 (p/i)·i + (p%i) ≡ 0 → ×i⁻¹ 得 i⁻¹ ≡ -(p/i)·(p%i)⁻¹
//即 inv[i] = (p - p/i)·inv[p%i] % p  (p-p/i ≡ -p/i, 避免负号)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);       // 3e6 行输出, 必须快
    cin.tie(nullptr);
    int n,p;
    cin>>n>>p;
    vector<ll> inv(n+1);
    inv[1]=1;
    cout<<inv[1]<<"\n";
    for(int i=2;i<=n;i++){
        inv[i]=(ll)(p-p/i)*inv[p%i]%p;   // (p-p/i)·inv[p%i] 最大 ~(2e7)², 必须转 ll
        cout<<inv[i]<<"\n";
    }
    return 0;
}
