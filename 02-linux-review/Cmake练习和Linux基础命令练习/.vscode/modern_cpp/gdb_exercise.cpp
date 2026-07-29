// GDB 深入练习 — 找出程序中所有的 bug
// 功能：输入一个数组，计算最大值、最小值、平均值，并反转数组
#include <iostream>
using namespace std;

void reverseArray(int arr[], int n){
    for(int i=0;i<n/2;i++){      // ？？
        int t=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=t;
    }
}

int main(){
    int n;
    cout<<"输入数组大小: ";
    cin>>n;
    int* arr = new int[n];
    cout<<"输入"<<n<<"个数:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // 计算最大值
    int maxVal = arr[0];
    for(int i=1;i<n;i++){       // ？？
        if(arr[i]>maxVal)
            maxVal=arr[i];
    }

    // 计算最小值
    int minVal=maxVal;
    for(int i=0;i<n;i++){
        if(arr[i]<minVal)
            minVal=arr[i];
    }

    // 计算平均值
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    double avg=(double)sum/n;

    cout<<"max="<<maxVal<<" min="<<minVal<<" avg="<<avg<<"\n";

    reverseArray(arr,n);

    cout<<"反转后: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    delete[] arr;
    return 0;
}
