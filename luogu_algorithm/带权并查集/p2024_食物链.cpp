#include<bits/stdc++.h>
using namespace std;
const int k=3;
int ans=0;
int N,K;
vector<int>fa,d;
int find(int x){
    if(fa[x]!=x){
        int root=find(fa[x]);
        d[x]=(d[x]+d[fa[x]])%k;
        fa[x]=root;
    }
    return fa[x];
}
void merge(int x,int y,int rel){
    int rx=find(x);
    int ry=find(y);
    if(rx==ry){
        if((d[x]-d[y]+k)%k!=rel)ans++;
    }
    else {
        fa[rx]=ry;
        d[rx]=(d[y]-d[x]+rel+k)%k;
    }
}
int main(){
    cin>>N>>K;
    fa.resize(N+1);d.resize(N+1);
    for(int i=1;i<=N;i++){
        fa[i]=i;
        d[i]=0;
}
    while(K--){
        long long op,x,y;
        cin>>op>>x>>y;
        if(x>N||y>N){ans++;continue;}
        if(x==y&&op==2){
            ans++;continue;
        }
        merge(x,y,op-1);
    }
    cout<<ans<<"\n";
    return 0;
}
