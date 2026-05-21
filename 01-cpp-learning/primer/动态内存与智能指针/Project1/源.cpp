#include<iostream>
#include<memory>
using namespace std;
class A {
public:
	A()=default;
	A(int x) :data(x){}
	int data = 0;
};
A* test(int x) {
	return new A(x);
	}
void use_test(int a) {
	A* p = test(a);
}//使用p但是不删除
int main() {
	//shared_ptr共享指针 最优创建：auto ptr=make_shared<T>(值)；
	// 特点：可拷贝、可赋值、多指针共用一块内存
	//禁止：不要裸指针初始化多个shared_ptr
	shared_ptr<int>p3 = make_shared<int>(42);//make_shared 返回指向int对象的shared_ptr
	shared_ptr<string>p4 = make_shared<string>(10, '9');
	cout << *p4 << endl;
	cout << p3<< endl;
	//使用new动态分配和初始化对象
	int* pi = new int;//pi指向一个动态分配的、为初始化的无名对象
	string* ps = new string;//初始化为空string
	string* ps1 = new string();
	//动态分配的const 对象
	const int* pci = new const int(2026);//合法,但必须初始化
	//释放内存
	int i, * pi1 = &i, * pi2 = nullptr;
	string* pS = new string("st"), * pss = pS;
	delete pi1;
	delete pS;
	delete pss;//未定义，pss指向的内存已经被释放，即上一步操作
	delete pi2;
	delete pci;//合法，const指向对象的值不可以被改变,但是对象可以被摧毁
	//有内置指针（非智能指针）管理的形态内存在显式释放前一直存在
	use_test(1);//
	//做法是在use_test中释放内存
}