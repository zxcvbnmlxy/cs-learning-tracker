//P1082 [NOIP2012 提高组 D2T1] 同余方程
//ax ≡ 1 (mod b) ⟺ b | (ax-1) ⟺ ax - by = 1 ⟺ exgcd 解 ax+by=1 (b 的系数负号吞进 y)
//exgcd 解出的 X 可能为负/超界, 答案 = 最小正 X, 即 (X%b+b)%b (互质⇒解在[1,b-1]唯一)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){ x=1,y=0; return a; }
    ll g=exgcd(b,a%b,x,y);
    ll temp=y;              // 全 ll 化: temp 与 y 同类型, 系数最大 ~2e9 接近 int 上限, 别混 int
    y=x-(a/b)*y;
    x=temp;
    return g;
}
int main(){
    ll a,b,X,Y;
    cin>>a>>b;
    exgcd(a,b,X,Y);
    cout<<(X%b+b)%b<<"\n";
    return 0;
}
