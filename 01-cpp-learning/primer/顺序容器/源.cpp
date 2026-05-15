#include<iostream>
#include<vector>
#include<deque>
#include<list>
using namespace std;
typedef vector<int> lis;
int main() {
	vector<int>x(10,10);
	vector<int>::iterator it = x.begin(),it1=x.end();
	lis::difference_type;
	list<string>a = { "m","n","t" };
	auto it2 = a.begin();//list<string>::iterator;
	auto it3 = a.end();//list<string>::iterator;
	list<string>::iterator it4 = a.begin();
	list<string>::iterator it5 = a.end();
	auto it7 = a.begin();//仅当a是const时，it7是const_iterator
	auto it8 = a.cbegin();//以c开头的迭代器是const_iterator
	//当不需要访问时，应使用cbegin()和cend
	vector<string>svec;
	svec.insert(svec.end(), "hello");
	cout << svec[0]<<endl;
	svec.insert(svec.begin(), 4, "world");//在svec开头插入4个world
	for (string s : svec)cout << s;
	deque<string>dq;
	string s;
	while (cin >> s) {
		dq.push_back(s);
		//dq.emplace_back(s);
	}
	for (auto it = dq.begin();it != dq.end();it++)
		cout << *it << endl;
	vector<int>vi(1,10);
	int some_val = 10;
	vector<int>::iterator iter = vi.begin(),
	mid = vi.begin() + vi.size() / 2;
	while (iter != mid) {
		if (*iter == some_val)
			vi.insert(iter, 2 * some_val);
	}
}