#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a;
vector<int>cnt;
int kind=0;
int mi=INT_MAX;
vector<pair<int,int>>ans;
void func(){
    int l=1;
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
        if(cnt[a[i]]==1)kind++;
        while(kind==m){
            ans.push_back({l,i});
            cnt[a[l]]--;
            mi=min(mi,i-l+1);
            if(cnt[a[l]]==0)kind--;
            l++;
        }
    }
    
}
int main(){
    cin>>n>>m;
    a.resize(n+1);
    cnt.resize(m+1);
    for(int i=1;i<=m;i++)cnt[i]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    func();
    for(auto [l,r]:ans){
        if(r-l+1==mi){cout<<l<<" "<<r;return 0;}
    }
    return 0;
}
