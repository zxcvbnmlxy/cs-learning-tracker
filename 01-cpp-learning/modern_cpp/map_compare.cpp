// ============================================
// map vs unordered_map 性能对比
// 练习目标：理解关联容器的选择
// ============================================

#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
using namespace std;

// 统计函数（模板，支持 map 和 unordered_map）
template<typename MapType>
void count_words(const string& filename, const string& label) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << label << ": 无法打开文件" << endl;
        return;
    }

    auto start = chrono::high_resolution_clock::now();

    MapType word_count;
    string word;
    while (file >> word) {
        word_count[word]++;
    }
    file.close();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // 转存并排序输出
    vector<pair<string,int>> words(word_count.begin(), word_count.end());
    sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    cout << "\n=== " << label << " (耗时: " << duration.count() << " μs) ===" << endl;
    int count = 0;
    for (const auto& [w, freq] : words) {
        cout << w << " : " << freq << endl;
        if (++count >= 5) break;
    }
}

int main() {
    count_words<map<string,int>>("sample.txt", "map（红黑树）");
    count_words<unordered_map<string,int>>("sample.txt", "unordered_map（哈希表）");
    return 0;
}
