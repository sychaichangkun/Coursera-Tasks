//
//#include <iostream>
//using namespace std;
// 在此处补充你的代码
class CType
{
public:
	int num;
	int setvalue(int n)
	{
		num = n;
		return n;
	}
	CType operator++(int)
	{
		CType old = *this;
		num = num*num;
		return old;
	}
};
ostream& operator<<(ostream& os, CType ob)
{
	os << ob.num;
	return os;
}
//
//int main(int argc, char* argv[]) {
//	CType obj;
//	int n;
//	cin >> n;
//	while (n) {
//		obj.setvalue(n);
//		cout << obj++ << " " << obj << endl;
//		cin >> n;
//	}
//
//	return 0;
//}
