// unordered_map 内部结构探索
// 目标：理解桶(bucket)、哈希冲突、负载因子
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    unordered_map<string,int>mp={
        {"apple",1},
        {"banana",2},
        {"cat",3},
        {"dog",4},
        {"elephant",5}
    };
    cout<<"bucket_count:"<<mp.bucket_count()<<endl;
    for(size_t i=0;i<mp.bucket_count();i++){
        cout<<"bucket "<<i<<" has "<<mp.bucket_size(i)<<" elements";
        // 遍历该桶内的所有元素，看具体是谁
        for(auto it=mp.begin(i);it!=mp.end(i);it++){
            cout<<" ["<<it->first<<":"<<it->second<<"]";
        }
        cout<<endl;
    }
    cout<<"load_factor:"<<mp.load_factor()<<endl;
    cout<<"max_load_factor:"<<mp.max_load_factor()<<endl;
    cout << "\n--- 插入更多元素，观察 rehash ---\n";
for (int i = 0; i < 10; i++) {
    string key = "key" + to_string(i);
    mp[key] = i;
    cout << "插入 " << key << " → size=" << mp.size()
         << " buckets=" << mp.bucket_count()
         << " load=" << mp.load_factor() << endl;
}

    return 0;
}