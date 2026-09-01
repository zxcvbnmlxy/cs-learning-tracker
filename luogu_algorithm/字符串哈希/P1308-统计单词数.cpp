//P1308 [NOIP2011 普及组] 统计单词数
//完整单词匹配: 大小写不敏感 + 前后必须是空格/边界
//首尾加空格大法: " "+word+" " 和 " "+article+" " → 边界自动变成"两侧必有空格", find substr 找完整块
//位置不偏移: 匹配 p 处的单词真实位置 = p (首空格+1 被尾部空格 -1 抵消)
#include<bits/stdc++.h>
using namespace std;
string turn(string &s){   // 转小写 + 补空格, 返回新串
    for(char &c:s)
        if(c>='A'&&c<='Z') c=c-'A'+'a';
    return " "+s+" ";
}
int main(){
    string word, article;
    getline(cin, word);   word=turn(word);
    getline(cin, article); article=turn(article);
    int len=word.size();
    int first=(int)article.size()-len;   // 初始化为最后合法位置, min 更新为第一次出现
    int cnt=0;
    for(int i=0;i<=(int)article.size()-len;i++){   // <= 别忘了最后一个合法位置
        if(article.substr(i,len)==word){
            cnt++;
            first=min(first,i);
        }
    }
    if(cnt==0) cout<<-1<<"\n";
    else cout<<cnt<<" "<<first<<"\n";
    return 0;
}
