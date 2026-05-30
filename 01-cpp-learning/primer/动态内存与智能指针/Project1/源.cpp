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
void process(shared_ptr<int>ptr) {};
int* f() {
	int* p = new int(3);
	shared_ptr<int>ssp(p);//从已有指针构造智能指针
	return p;
}
int main() {
	//shared_ptr共享指针 最优创建：auto ptr=make_shared<T>(值)；
	// 特点：可拷贝、可赋值、多指针共用一块内存
	//禁止：不要裸指针初始化多个shared_ptr
	shared_ptr<int>p3 = make_shared<int>(42);//make_shared 返回指向int对象的shared_ptr
	shared_ptr<string>p4 = make_shared<string>(10, '9');
	cout << *p4 << endl;
	cout << p3<< endl;

	int *ptr=f();
	cout << *ptr << endl;//危险，未定义;裸指针构造智能指针需要保证原指针指向的对象没有被智能指针释放，
	//此例中，在函数f中将ssp指向p指向的对象，ssp作用域为f，离开作用域ssp被释放，对象被销毁，ptr成为野指针
	
	//使用new动态分配和初始化对象
	int* pi = new int;//pi指向一个动态分配的、为初始化的无名对象
	string* ps = new string;//初始化为空string
	string* ps1 = new string();

	//动态分配的const 对象
	const int* pci = new const int(2026);//合法,但必须初始化
	//释放内存
	int i, * pi1 = &i, * pi2 = nullptr;
	string* pS = new string("st"), * pss = pS;
	//delete pi1;//未定义，删除指向栈内存，i是栈内的局部变量
	delete pS;
	//delete pss;//未定义，pss指向的内存已经被释放，即上一步操作
	delete pi2;
	delete pci;//合法，const指向对象的值不可以被改变,但是对象可以被摧毁
	//有内置指针（非智能指针）管理的形态内存在显式释放前一直存在
	use_test(1);//
	//做法是在use_test中释放内存

	//动态内存的管理很容易出错
	//1 忘记delete内存，忘记释放内存，“内存泄漏”；
	//2 使用释放掉的对象，通过释放内存后指针悬空
	//3 同一块内存被释放两次，当有两个指针指向相同的动态分配对象时，可能发生

	//坚持只使用只能指针，可以避免；对于一块内存，只有在没有任何智能指针指向他，智能指针会主动释放

	int* p(new int(91));
	auto q = p;
	delete p;
	p = nullptr;
	//cout << *q<<endl;//错误，访问已经释放的内存
	
	//接受指针参数的智能指针构造函数是explicit的。必须使用直接初始化形式来初始化一个智能指针
	//shared_ptr<int>p1 = new int(1024);//错误，不存在从int到shared_ptr<int>的构造函数
	shared_ptr<int>p2(new int(1024));//正确：直接初始化
	int* x(new int(2048));
	//process(x);//错误，不存在int*到shared_ptr<int>的构造函数
	process(shared_ptr<int>(x));//合法，但x指向的内存会被释放,在process引用计数+1，离开process作用域，引用计数-1
	cout << "悬浮指针" << endl;
	cout << *x << endl;
	//使用一个内置指针来访问一个智能指针所负责的对象是很危险的，对象何时被销毁不知

	/*auto sp = make_shared<int>();
	auto pp = sp.get();
	delete pp;*/ //直接报错，double free sp.get(),返回shared_ptr管理的裸指针pp
	//永远不要手动删除shared_ptr::get（）返回的裸指针，
	//
}