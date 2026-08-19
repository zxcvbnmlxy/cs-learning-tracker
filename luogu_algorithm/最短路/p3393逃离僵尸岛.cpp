#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,p,q;
const long long INF=4e18;
int main(){
    cin>>n>>m>>k>>s>>p>>q;
    vector<bool>is(n+1,false);
    vector<vector<int>>g(n+1);
    queue<int>qq;
    vector<int>source;
    for(int i=0;i<k;i++){
        int c;cin>>c;is[c]=true;
        source.push_back(c);
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // vector<bool>vis(n+1,false);
    vector<int>distance(n+1,-1);
    for(auto &s:source){
        distance[s]=0;
        qq.push(s);
    }
    while(!qq.empty()){
        auto u=qq.front();
        qq.pop();
            for(auto v:g[u]){
                if(distance[v]==-1){
                distance[v]=distance[u]+1;
                qq.push(v);
            }
        }
    }
    long long cost[n+1]={0};
    for(int i=1;i<=n;i++){
        if(is[i])cost[i]=-1;
        else if(distance[i]!=-1&&distance[i]<=s){
            cost[i]=q;
        }
        else{
            cost[i]=p;
        }
    }
    cost[1]=0;
    cost[n]=0;
    vector<long long>minCost(n+1,INF);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long ,int>>>pq;
    minCost[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [curcost,u]=pq.top();pq.pop();
        if(curcost!=minCost[u])continue;
        if(u==n)break;
        for(auto v:g[u]){
            if(is[v])continue;
            if(curcost+cost[v]<minCost[v]){
                minCost[v]=curcost+cost[v];
                pq.push({minCost[v],v});}
        }
    }
    cout<<minCost[n];
    return 0;
}
