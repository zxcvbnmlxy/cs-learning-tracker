#include<bits/stdc++.h>   // 万能头：一次性包含 STL + cmath（sqrt 在这）
using namespace std;

int main(){
    // ================= 1. 读入 =================
    int n;                 // 奶酪块数（n≤15，决定状态量 2^n）
    cin>>n;

    double x[20], y[20];   // 每块奶酪坐标（允许负值，double 存，别用 int）
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];

    // ================= 2. 距离表（预处理，避免转移里反复算 sqrt） =================
    double dist[20][20];   // dist[i][j] = 点 i 到点 j 的欧氏距离
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    // 负号只出现在差值里，一平方就消失，dist 恒非负

    // ================= 3. dp 数组（状压 DP 核心） =================
    // dp[mask][i]：已吃集合 = mask（第 i 位 = 1 表示奶酪 i 已吃），当前停在奶酪 i 的最小路程
    // 状态数 = 2^n 个集合 × n 个停点；1e18 = 无穷大（该状态暂不可达）
    vector<vector<double>> dp(1<<n, vector<double>(n, 1e18));

    // ================= 4. 初始化：第一块 =================
    // 第一块之前只能从原点 (0,0) 出发 → 只吃奶酪 i 的状态，距离 = 原点→i
    for(int i=0;i<n;i++)
        dp[1<<i][i] = sqrt(x[i]*x[i]+y[i]*y[i]);

    // ================= 5. 转移（核心双循环） =================
    // mask 从小到大枚举：转移只会 OR 进新位（数字只变大）→ 天然拓扑序，不用 DFS 也不用记忆化
    for(int mask=0; mask<(1<<n); mask++){          // 外层：枚举当前已吃集合
        for(int i=0;i<n;i++){                       // 中层：枚举当前停在哪个点
            if((mask&(1<<i))==0) continue;          // 条件1：mask 里必须有 i（没吃它，不可能停在那）
            if(dp[mask][i]==1e18) continue;         // 条件2：该状态可达（不是无穷大才转移）
            for(int j=0;j<n;j++){                   // 内层：枚举下一块吃哪个
                if((mask&(1<<j))!=0) continue;      // 条件3：mask 里必须没有 j（已吃的不能重复吃）
                // 新状态 = 旧集合 OR 进 j、停在 j；多条路可达 → 取 min
                dp[mask|(1<<j)][j] = min(dp[mask|(1<<j)][j], dp[mask][i]+dist[i][j]);
            }
        }
    }

    // ================= 6. 答案 =================
    // 全吃完 = mask 是 (1<<n)-1；最后停在哪个点都行 → 对 i 取最小
    double ans=1e18;
    for(int i=0;i<n;i++)
        ans=min(ans, dp[(1<<n)-1][i]);

    cout<<fixed<<setprecision(2)<<ans;   // 保留两位小数
    return 0;
}
