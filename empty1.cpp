// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int n,k;
// int cnt=0;
// vector<int>a;
// bool is(ll&x){
//     if(x<2)return false;
//     for(ll i=2;i*i<=x;i++){
//         if(x%i==0)return false;
//     }
//     return true;
// }
// void dfs(int start,int depth,ll sum){
//     if(depth==k){
//         if(is(sum))cnt++;
//     }
//     for(int i=start;i<n;i++){
//         dfs(i+1,depth+1,sum+a[i]);
//     }
// }
// int main(){
//     cin>>n>>k;
//     a.assign(n,0);
//     for(int i=0;i<n;i++)cin>>a[i];
//     dfs(0,0,0);
//     cout<<cnt<<"\n";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// bool col[20]={false},udg[40]={false},dg[40]={false};
// int graph[20];
// int n;
// int cnt=0;
// void dfs(int row){
//     if(row>n){
//         cnt++;
//         if(cnt<=3){
//         for(int i=1;i<=n;i++){
//             cout<<graph[i]<<((i==n)?"\n":" ");//?:优先级小于<<
//         }
//     }
//         return ;
//     }
//     for(int j=1;j<=n;j++){
//         if(!col[j]&&!dg[row+j]&&!udg[row-j+n]){
//             graph[row]=j;
//             col[j]=dg[row+j]=udg[row-j+n]=true;
//             dfs(row+1);
//             col[j]=dg[row+j]=udg[row-j+n]=false;;
//         }
//     }
// }
// int main(){
//     cin>>n;
//     dfs(1);
//     cout<<cnt;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     vector<int>in;
//     queue<int>q;
//     cin>>n;
//     vector<vector<int>>g(n+1);
//     vector<int>len(n+1);
//     vector<int>time(n+1,0);
//     in.assign(n+1,0);
//     for(int i=1;i<=n;i++){
//         int id,t,pre;
//         cin>>id>>t;
//         len[id]=t;
//         time[id]=t;
//         while(cin>>pre&&pre!=0){
//             g[pre].push_back(id);
//             in[id]++;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         if(in[i]==0)q.push(i);
//     }
//     while(!q.empty()){
//         int u=q.front();
//         q.pop();
//         for(auto &v:g[u] ){
//             time[v]=max(time[v],time[u]+len[v]);
//             in[v]--;
//             if(in[v]==0)q.push(v);
//         }
//     }
//     cout<<*max_element(time.begin()+1,time.end())<<"\n";
//     return 0;

// }

// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// struct Edge{
//     int u,v,w;
// };
// vector<Edge>e;
// vector<int>fa;
// int find(int x){
//     if(fa[x]!=x)
//     fa[x]=find(fa[x]);
//     return fa[x];
// }
// void unite(int x,int y){
//     int rx=find(x),ry=find(y);
//     if(rx==ry)return ;
//     if(rx>ry)swap(rx,ry);
//     fa[ry]=rx;
// }
// int main(){
//     cin>>n>>m;
//     fa.assign(n+1,0);
//     e.resize(m);
//     for(int i=0;i<m;i++){
//         cin>>e[i].u>>e[i].v>>e[i].w;
//         fa[e[i].u]=e[i].u;
//         fa[e[i].v]=e[i].v;
//     }
//     int ans=0,cnt=0;
//     sort(e.begin(),e.end(),[](Edge& e1,Edge& e2){return e1.w<e2.w;});
//     for(int i=0;i<m;i++){
//         if(find(e[i].u)!=find(e[i].v)){
//             unite(e[i].u,e[i].v);
//             ans+=e[i].w;
//             cnt++;
//         }
//     }
//      if(cnt==n-1)cout<<ans;
//      else cout<<"orz";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int INF=1e8;
// struct edg{
//     int v,w;
// };
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int>dist(n+1,INF);
//     vector<vector<edg>>g(n+1);
//     dist[1]=0;
//     for(int i=0;i<m;i++){
//         int u,v,w;
//         cin>>u>>v>>w;
//         g[u].push_back({v,w});
//         g[v].push_back({u,w});
//     }
//     vector<bool>vis(n+1,false);
//     priority_queue<pair<int ,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     pq.push({0,1});
//     int ans=0,cnt=0;
//     while(!pq.empty()){
//         auto [d,u]=pq.top();pq.pop();
//         if(vis[u])continue;
//         vis[u]=true;
//         cnt++;ans+=d;
//         for(auto &[v,w]:g[u]){
//             if(!vis[v]&&w<dist[v]){
//                 dist[v]=w;
//                 pq.push({w,v});
//             }
//         }
//     }
//     if(cnt==n)cout<<ans;
//     else cout<<"orz";
//     return 0;
// }