// GDB 复习 — 用 GDB 找出所有 bug
// 功能1：判断一个数是不是素数
// 功能2：计算 1! + 2! + ... + n!
// 功能3：二分查找
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

long long factorial(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

long long sumFactorial(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += factorial(i);
    }
    return sum;
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int sumArray(int arr[], int n) {
    int sum=0;
    for (int i = 0; i <n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // 测试素数
    cout << "isPrime(7) = " << isPrime(7) << "\n";
    cout << "isPrime(1) = " << isPrime(1) << "\n";
    cout << "isPrime(9) = " << isPrime(9) << "\n";

    // 测试阶乘和
    cout << "sumFactorial(3) = " << sumFactorial(3) << "\n";
    int a[5] = {1, 3, 5, 7, 9};
    int idx = binarySearch(a, 5, 7);
    cout << "binarySearch 7 = " << idx << "\n";

    // 测试数组求和
    int b[5] = {1, 2, 3, 4, 5};
    int s = sumArray(b, 5);
    cout << "sum = " << s << "\n";
    cout<<"完成";
    return 0;
}
