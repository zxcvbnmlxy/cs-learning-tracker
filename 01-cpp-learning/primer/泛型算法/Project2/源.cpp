#include<iostream>
#include<vector>
#include<numeric>
#include<iterator>
#include<algorithm>
using namespace std;
void del(vector<string> &s) {
	sort(s.begin(), s.end());
	for (auto ss : s)cout << ss << " ";
	cout << endl;
	auto end_unique = unique(s.begin(), s.end());
	s.erase(end_unique, s.end());
	for (auto ss : s)cout << ss << " ";
	cout << endl;
}
void func() {
	int x = 10;
	auto sum = [x](int y) {return x + y;};
	cout << sum(81) << endl;
}
int main() {
	vector<int>s;
	for (int i = 0;i < 5;i++) {
		s.push_back(i * 2 + 1);
	}
	int sum=accumulate(s.cbegin(), s.cend(), 1);//26
	for (auto c : s)cout << c << " ";
	cout << sum<<"\n";

	//equal比较两个序列是否存在完全相同的序列,将两个序列进行对比，
	// 若第一个序列中的每一个元素都与第二个序列中的对应元素一一相等，则返回true
	cout << "----equal----" << endl;
	vector<int>x;
	for (int i = 0;i < 4;i++) {
		x.push_back(2 * i + 1);
	}
	//x.push_back(10);
	bool eq=equal(x.cbegin(), x.cend(), s.cbegin());
	cout << eq<<"\n";

	//fill_n fill_n(起始迭代器, 填充个数, 填充值) 
	cout << "----fill_n----" << endl;
	vector<int>vec;
	fill_n(vec.begin(), vec.size(), 10);
	for (auto c : vec)cout << c << " "<<endl;

	//back_inserter 自动扩容，生成尾部迭代器back_insert_iterator
	cout << "----back_inserter----" << endl;
	vector<int>v;
	auto it = back_inserter(v);//参数：传入一个容器的引用，返回该容器的迭代器
	*it = 10;
	cout << v[0]<<endl;
	fill_n(back_inserter(v), 10, 0);//v.size=10;
	for (auto x : v)cout << x << " ";
	cout << endl;

	//copy copy只会覆盖已有元素，不会扩容
	cout << "----copy----" << endl;
	int a1[] = { 0,1,2,3,4,5,6,7 };
	vector<int>a2;
	//int a2[7];报错，a2元素个数至少与输入序列相等
	auto pos=copy(cbegin(a1),cend(a1), back_inserter(a2));//返回的是复制完之后的尾迭代器的值（相当于a2.end()）,可以忽略
	//cout << *pos;
	for (auto x : a2)cout << x << " " << endl;

	//unique只消除相邻的重复项
	cout << "----unique----" << endl;
	vector<string>words = { "fox","red","jumps","dog","lxy","red","lxy","lxy"};
	del(words);
	for (auto w : words)cout << w << " ";cout << endl;

	//lambda表达式 [capture list](parameter list)->return type{function body};必须包含捕获列表和函数体
	cout << "----lambda----" << endl;     //注意⚠️：被捕获变量的值是在lambda创建时拷贝的
	auto f = [] {return 42;};
	cout << f() << endl;
	int a = 78, b = 13;
	auto f1 = [a, b] {return a + b;};
	cout <<"a+b=" << f1() << endl;
	func();
}