#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int n;
bool col[20]={false},udg[40]={false},dg[40]={false};
int graph[20];  
void dfs(int row){
    if(row>n){
        cnt++;
        if(cnt<=3){
            for(int i=1;i<=n;i++){
                cout<<graph[i]<<((i==n)?"\n":" ");
            }
        }
    }
    for(int j=1;j<=n;j++){
        if(!col[j]&&!udg[row-j+n]&&!dg[row+j]){
            graph[row]=j;
            col[j]=dg[row+j]=udg[row-j+n]=true;
            dfs(row+1);
            col[j]=dg[row+j]=udg[row-j+n]=false;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
    cout<<cnt;
    return 0;
}
