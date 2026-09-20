#include<bits/stdc++.h>
using namespace std;
vector<int>fa;
vector<int>d;
const int k=3;
int cnt=0;
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
        if((d[x]-d[y]+k)%k!=rel){
            cnt++;
        }
    }
    else {
    fa[rx]=ry;
    d[rx]=(d[y]-d[x]+rel+k)%k;
    }
}
int main(){
    int n,K;
    cin>>n>>K;
    fa.resize(n+1);
    d.assign(n+1,0);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    while(K--){
        int op,x,y;cin>>op>>x>>y;
        if(op==2&&x==y){cnt++;continue;}
        if(x>n||y>n){cnt++;continue;}
        if(op==1){
            merge(x,y,0);
        }
        else merge(x,y,1);
    }
    cout<<cnt;
    return 0;
}