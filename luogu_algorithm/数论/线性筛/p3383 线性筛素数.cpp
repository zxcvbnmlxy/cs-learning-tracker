// //埃氏筛
// #include<bits/stdc++.h>
// using namespace std;
// vector<bool>isPrime;
// vector<int>primes;
// int main(){
//     int n,q;
//     cin>>n>>q;
//     isPrime.assign(n+1,true);
//     isPrime[0]=isPrime[1]=false;
//     for(int i=2;i<=n;i++){
//         if(isPrime[i]){
//             primes.push_back(i);
//             for(int j=i*i;j<=n;j+=i){
//                 isPrime[j]=false;
//             }
//         }
//     }
//     while(q--){
//         int x;cin>>x;
//         cout<<(isPrime[x]?"Yes":"No")<<endl;
//     }
//     return 0;
// }

//线性筛
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// vector<bool>isPrime;
// vector<ll>primes;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(nullptr);
//     int n,q;
//     cin>>n>>q;
//     isPrime.assign(n+1,true);
//     isPrime[0]=isPrime[1]=false;
//     for(int i=2;i<=n;i++){
//         if(isPrime[i])
//             primes.push_back(i);
//         for(int j=0;j<primes.size()&&i<=n/primes[j];j++){
//             isPrime[primes[j]*i]=false;
//             if(i%primes[j]==0)break;
//         }
//     }
//     while(q--){
//         ll x;
//         cout<<primes[x-1]<<"\n";
//     }
//     return 0;
// }
//辗转相除法，欧几里得
// #include<bits/stdc++.h>
// using namespace std;
// int gcd(int a,int b){
//     return b?gcd(b,a%b):a;
// }
// int exgcd(int a,int b,int &x,int &y){
//     int g;
//     if(b==0){
//         x=1,y=0;return a;
//     }
//     else {
//         g=exgcd(b,a%b,x,y);
//         int temp=y;
//         y=x-(a/b)*y;
//         x=temp;
//     }
//     return g;
// }
// int main(){
//     int x,y;
//     exgcd(17,7,x,y);
//     cout<<x<<" "<<y<<"\n";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int exgcd(int a,int b,ll &x,ll &y){
    int g;
    if(b==0){
        x=1,y=0;return a;
    }
    else {
        g=exgcd(b,a%b,x,y);
        int temp=y;
        y=x-(a/b)*y;
        x=temp;
    }
    return g;
}
int main(){
    cin>>a>>b;
    ll X,Y;
    int x=exgcd(a,b,X,Y);
    cout<<(X%b+b)%b<<endl;
    return 0;
}