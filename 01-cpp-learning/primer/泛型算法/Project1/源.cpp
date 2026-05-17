#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
#include<list>
using namespace std;
int main() {
	vector<int>vec = { 1,42 };
	int val = 42;
	auto result = find(vec.begin(), vec.end(), val);//返回指向第一个等于该定参数的迭代器
	//若返回值与end()相等，则不存在
	//find操作的是迭代器
	string val1 = "a value";
	//auto result = find(val1.begin(), val1.end(), val);
	int ia[] = { 27,210,12,47,109,83 };
	val = 83;
	//int* result = find(begin(ia), end(ia), val);
	vector<int>test = { 1,2,3,4,5,4,2,3,4 };
	val = 4;
	int ans = count(test.begin(), test.end() - 1, val);//test中有多少个元素等于罢了；
	cout << ans << endl;
	//泛型算法不会操作容器本身，操作迭代器

	//只读算法
	//accumulate接受三个参数，前两个参数指明求和的元素的范围，第三个参数是和的初值
	int sum = accumulate(vec.cbegin(), vec.cend(), 0);
	cout << sum << endl;
	//equal 用于确定两个序列是否保存相同的值，若所有对应元素都相同返回true，
	vector<int>t1 = { 1,2,3,4,5,6,8,7 }, t2 = { 1,2,3,4,5,6,7,8 };
	list<int>t3 = { 1,2,3,4,5,6,7,8 };
	cout<<equal(t1.cbegin(), t1.cend(), t2.cbegin())<<endl;//0
	cout << equal(t1.cbegin(), t1.cend(), t3.begin())<<endl;//0容器类型可以不同，元素类型也不必一样，只要可以用来比较
	cout << equal(t2.cbegin(), t2.cend(), t3.begin());//1
	//lambda表达式 [capture list](paramert list)->return type{type body}
	auto f = [] {return 42;};//可以忽略参数列表和返回类型，但必须包含捕获列表和函数体，捕获列表只用于局部非static
	//捕获列表捕获的是变量本身、变量副本、变量引用，捕获发生在定义时
	cout << f() << endl;//lambda调用方式和函数调用方式一样
	vector<int>x = { 0,10,2,3 };
	sort(x.begin(), x.end(), [](int a, int b) {return a > b;});//自定义排序
	for (int a : x)cout << a<<endl;



}