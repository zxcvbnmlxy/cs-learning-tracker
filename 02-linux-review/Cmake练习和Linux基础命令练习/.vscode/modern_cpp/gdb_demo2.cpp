// GDB 条件断点演示
// 找出一组分数中第一个低于60分的
#include <iostream>
using namespace std;

int main(){
    int scores[]={88,92,73,55,68,45,90,38,82,95};
    for(int i=0;i<10;i++){
        cout<<"第"<<i+1<<"个分数: "<<scores[i];
        if(scores[i]>=60)
            cout<<" 及格\n";
        else
            cout<<" 不及格！\n";
    }
    return 0;
}
