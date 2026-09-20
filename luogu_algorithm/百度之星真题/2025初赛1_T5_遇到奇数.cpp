// 百度之星 2025 初赛第一轮 T5「遇到奇数」/ Odd Occurrence
// 判据：序列中每个出现过的值的出现次数 c，都必须是 2^t - 1（即 c+1 是 2 的幂）
// 等价写法：c & (c+1) == 0
#include<bits/stdc++.h>

using namespace std;

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t,n;cin>>t;
    while(t--){
        cin>>n;
        vector<int>cnt(n+1,0);
        for(int i=0;i<n;i++){
            int x;cin>>x;
            cnt[x]++;
        }
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(cnt[i]==0){
                continue;
            }
            else {
                if(((cnt[i]+1)&cnt[i])!=0){
                    flag=true;
                    break;
                }
            }
        }
        cout<<((flag)?"No":"Yes")<<"\n";

    }
    return 0;
}
