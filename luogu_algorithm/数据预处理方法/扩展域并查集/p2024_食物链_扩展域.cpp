// P2024 食物链 — 扩展域并查集解法（3 域）
// 对动物 x 拆 3 个身份：
//   x     : 同类域（和 x 同种动物）
//   x+n   : 猎物域（x 吃的东西）
//   x+2n  : 天敌域（吃 x 的东西）
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 50005 * 3;
int fa[MAXN];
int find(int x) { return fa[x]==x ? x : fa[x]=find(fa[x]); }
void merge(int a, int b) { int ra=find(a), rb=find(b); if(ra!=rb) fa[ra]=rb; }

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 3*n; i++) fa[i] = i;
    int ans = 0;
    while (m--) {
        int op, x, y; cin >> op >> x >> y;
        if (x > n || y > n) { ans++; continue; }
        if (op == 1) {   // 同类
            if (find(x)==find(y+n) || find(x)==find(y+2*n)) ans++;  // y吃x 或 x吃y → 假
            else {
                merge(x, y);
                merge(x+n, y+n);
                merge(x+2*n, y+2*n);
            }
        } else {         // 吃
            if (x == y) ans++;
            else if (find(x)==find(y) || find(x)==find(y+n)) ans++;  // 同类 或 y吃x → 假
            else {
                merge(y, x+n);
                merge(x, y+2*n);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
