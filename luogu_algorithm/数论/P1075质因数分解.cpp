//P1075 [NOIP2012 普及组] 质因数分解
//n 是两个不同质数 p<q 的乘积, 求较大的 q —— 第一个整除 n 的 i 就是 p, 答案 = n/p
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
    cin>>n;
    for(int i=2;i<=n/i;i++){     // 试除到 √n; i<=n/i 除法比较防溢出(和线性筛 i<=n/primes[j] 同款)
        if(n%i==0){
            cout<<n/i<<"\n";
            return 0;
        }
    }
    return 0;
}
