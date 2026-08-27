#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,p;
    cin>>a>>b>>p;
    ll base=a%p;
    ll ans=1;
    ll exp=b;
    while(exp>0){
        if((exp&1)==1)ans=ans*base%p;
        base=base*base%p;
        exp=exp>>1;
    }
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<ans<<endl;
    return 0;
}