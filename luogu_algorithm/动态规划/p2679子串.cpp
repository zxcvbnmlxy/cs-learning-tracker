#include<bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
string A,B;
long long f[2][205][205][2];   // 改成 long long 防溢出
int n,m,k;
int main(){
    cin>>n>>m>>k;
    cin>>A>>B;
    int now=0,nxt=1;
    f[now][0][0][0]=1;
    for(int i=1;i<=n;i++){
        memset(f[nxt],0,sizeof(f[nxt]));
        f[nxt][0][0][0]=1;
        for(int j=1;j<=m;j++){
            for(int t=1;t<=k;t++){
                if(A[i-1]==B[j-1]){
                    f[nxt][j][t][1]=(f[now][j-1][t-1][1]+f[now][j-1][t][1]+f[now][j-1][t-1][0])%MOD;
                }
                f[nxt][j][t][0]=(f[now][j][t][1]+f[now][j][t][0])%MOD;
            }
        }
        swap(now,nxt);
    }
    cout<<(f[now][m][k][0]+f[now][m][k][1])%MOD;
    return 0;
}
