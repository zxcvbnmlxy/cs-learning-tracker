// P1892 扩展域并查集 · 逐步动画演示
// 编译运行：g++ -g -O0 p1892_动画演示.cpp -o p1892_demo && ./p1892_demo
// 通过逐步打印 fa 数组，亲眼看到"敌人的敌人是朋友"如何被并查集自动算出来

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3050;
int fa[MAXN];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int a, int b) { int ra = find(a), rb = find(b); if (ra != rb) fa[ra] = rb; }

void show(int n, const string &title)
{
    cout << "──── " << title << " ────\n";
    cout << "fa[真实]1~6 : ";
    for (int i = 1; i <= n; i++) cout << setw(3) << fa[i];
    cout << "\nfa[镜像]7~12: ";
    for (int i = n + 1; i <= 2 * n; i++) cout << setw(3) << fa[i];
    cout << "\n每人所属团伙根: ";
    for (int i = 1; i <= n; i++) cout << i << "→" << find(i) << "  ";
    cout << "\n\n";
}

int main()
{
    int n = 6;
    for (int i = 1; i <= 2 * n; i++) fa[i] = i;
    show(n, "帧0 初始：12 个节点全部独立");

    cout << "【E 1 4】merge(1, 4+6=10) 把 1 扔进 4 的镜像；merge(4, 1+6=7) 把 4 扔进 1 的镜像\n\n";
    merge(1, 4 + n); merge(4, 1 + n);
    show(n, "帧1 E 1 4 之后");

    cout << "【F 3 5】朋友 → 真实世界直接连\n\n";
    merge(3, 5);
    cout << "【F 4 6】朋友 → 真实世界直接连（4 的根是 7，所以 7 也跟到 6）\n\n";
    merge(4, 6);
    show(n, "帧2 F 3 5 + F 4 6 之后");

    cout << "【E 1 2】merge(1, 2+6=8)；merge(2, 1+6=7) 把 2 扔进 1 的镜像\n"
            "⚠ 但 7 里已经有 4 了！→ 2 自动和 4 成为朋友（敌人的敌人是朋友）\n\n";
    merge(1, 2 + n); merge(2, 1 + n);
    show(n, "帧3 E 1 2 之后（魔法时刻）");

    cout << "【数团伙】统计 1~6 中不同根的数量\n";
    bool vis[MAXN] = {false};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int r = find(i);
        if (!vis[r]) { vis[r] = true; ans++; }
    }
    cout << "→ 输出 ans = " << ans << "\n";
    return 0;
}
