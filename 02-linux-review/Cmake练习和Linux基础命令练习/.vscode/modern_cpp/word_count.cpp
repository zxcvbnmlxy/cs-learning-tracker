// ============================================
// map 词频统计 + sort + lambda 排序输出
// 练习目标：map/unordered_map + lambda + sort
// ============================================

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    ifstream file("sample.txt");
    if(!file.is_open()){
        cout<<"Failed to open file."<<endl;return 0;
    }
    unordered_map<string,int>word_count;
    string word;
    while(file>>word){
        word_count[word]++;
    }

    // 转存到 vector<pair> 才能按 value 排序
    vector<pair<string,int>> words(word_count.begin(),word_count.end());
    sort(words.begin(),words.end(),[](const auto& a,const auto& b){
        return a.second>b.second;   // 按频次降序
    });

    cout<<"top 10"<<endl;
    int count=0;
    for(const auto& [w,freq]:words){
        cout<<w<<":"<<freq<<endl;
        if(count++>=9)break;
    }
    return 0;
}
