#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>dir={{0,-1},{-1,0},{0,1},{1,0}};
int main(){
    int n;cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
            if((i==0||i==n-1||j==n-1||j==0)&&graph[i][j]==0){
                q.push({i,j});graph[i][j]=-1;
            }
        }
    }
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(auto [dx,dy]:dir){
            int nx=x+dx,ny=y+dy;
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&graph[nx][ny]==0){
                q.push({nx,ny});graph[nx][ny]=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==-1)graph[i][j]=0;
            else if(graph[i][j]==0)graph[i][j]=2;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
