#include<iostream>
using namespace std;
class Sales_data {
	
public:
	Sales_data() = default;
	Sales_data(const string&s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
	Sales_data(istream&);
	string isbin()const { return bookNo; }
	double GetR() { return revenue; }
	Sales_data& combine(const Sales_data&);
	
private:
	string bookNo;
	double revenue=0.0;
	unsigned units_sold=0 ;
};
struct X {
	X(const string &name):s(name){}
	X() = default;
	int count=0;
	string s="he";
};
int main() {
	X x;
	cout << x.count << endl;
	cout << x.s;
	Sales_data d;
	cout << d.isbin() << endl;
	cout << d.GetR() << endl;
	//cout << d.units_sold<<endl;
}