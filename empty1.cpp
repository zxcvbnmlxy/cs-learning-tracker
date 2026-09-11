#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int cnt=0;
vector<ll>a;
bool is(ll&x){
    if(x==2)return true;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
void dfs(int start,int depth,ll sum){
    if(start>=n-1)return;
    if(depth==k){
        if(is(sum))cnt++;
    }
    for(int i=start;i<n;i++){
        dfs(i+1,depth+1,sum+a[i]);
    }
}
int main(){
    cin>>n>>k;
    a.ssign(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    dfs(0,0,0);
    cout<<cnt<<"\n";
    return;
}