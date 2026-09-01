//P3370 【模板】字符串哈希
//给 n 个字符串, 数不同的有多少个 → 每串算一个 base-131 指纹进 set 去重
//哈希 = b 进制大数: hash = hash*131 + c (c 为字符 ASCII), ull 自然溢出即 mod 2^64
//base 必须是 > 字符集 的奇数: 131>128 装得下所有字符(不进位污染), 奇数 mod 2^64 不消失
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull getHash(const string &s){
    ull h=0;
    for(char c:s) h=h*131+(ull)c;   // 注意是 = 不是 += (+= 会把 base 变 132 偶数)
    return h;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    unordered_set<ull> st;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.insert(getHash(s));
    }
    cout<<st.size()<<"\n";
    return 0;
}
