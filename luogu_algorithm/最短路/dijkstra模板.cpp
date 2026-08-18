#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;                     // 大一点的无穷，防止加边权溢出
int main(){
    int n=5;
    // 邻接表：g[u] 里存所有 (v, w) 表示 u -> v 边权 w
    vector<vector<pair<int,int>>> g(n+1);
    g[1].push_back({2,2}); g[1].push_back({3,5});
    g[2].push_back({1,2}); g[2].push_back({3,1}); g[2].push_back({4,6});
    g[3].push_back({1,5}); g[3].push_back({2,1}); g[3].push_back({4,1}); g[3].push_back({5,3});
    g[4].push_back({2,6}); g[4].push_back({3,1}); g[4].push_back({5,4});
    g[5].push_back({3,3}); g[5].push_back({4,4});

    vector<long long> dist(n+1, INF);
    dist[1]=0;                                // 只初始化起点，其余全 INF
    priority_queue<pair<long long,int>> pq;   // 大顶堆存负距离 = 最小堆
    pq.push({0,1});                           // 塞 (距离, 节点)，起点距离 0

    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        d=-d;                                 // 取回真实距离
        if(d!=dist[u]) continue;              // 过期条目（u 又被松弛过），扔掉
        for(auto [v,w]:g[u]){
            if(dist[u]+w<dist[v]){            // 松弛：绕 u 去 v 更便宜
                dist[v]=dist[u]+w;
                pq.push({-dist[v],v});        // 新距离塞堆（负的）
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<i<<" : "<<dist[i]<<endl;
    return 0;
}
