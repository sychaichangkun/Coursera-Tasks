//#include <iostream>
//#include <set>
//#include <iterator>
//#include <algorithm>
//using namespace std;
// 在此处补充你的代码
class A
{
public:
	char name;
	int age;
	A() {}
	A(int k) :age(k), name('A') {}
};
class B :public A
{
public:
	B(int k)
	{
		name = 'B';
		age = k;
	}
};
class Comp
{
public:
	bool operator()(A* a, A* b)
	{
		return a->age < b->age;
	}
};
void Print(A* p)
{
	cout << p->name << " " << p->age << endl;
}
//
//int main()
//{
//	int t;
//	cin >> t;
//	set<A*, Comp> ct;
//	while (t--) {
//		int n;
//		cin >> n;
//		ct.clear();
//		for (int i = 0; i < n; ++i) {
//			char c; int k;
//			cin >> c >> k;
//
//			if (c == 'A')
//				ct.insert(new A(k));
//			else
//				ct.insert(new B(k));
//		}
//		for_each(ct.begin(), ct.end(), Print);
//		cout << "****" << endl;
//	}
//
//
//	return 0;
//}