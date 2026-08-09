#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3050;
int fa[MAXN];
int find(int x)
{
    if (fa[x]!= x)
        fa[x]= find(fa[x]);
    return fa[x];
}
void merge(int a,int b){
    int ra=find(a);
    int rb=find(b);
    if(ra!=rb)
        fa[ra]=rb;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n*2;i++)fa[i]=i;
    while(m--){
        char op ;
        int x,y;cin>>op>>x>>y;
        if(op=='F')merge(x,y);
        else {
            merge(x,y+n);
            merge(y,n+x);
        }
    }
    int ans=0;
    vector<bool>vis(MAXN,false);
    for(int i=1;i<=n;i++){
        int r=find(i);
        if(!vis[r]){
            vis[r]=true;
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}