#include <iostream>
using namespace std;
class A {
public:
	int val;
	// 在此处补充你的代码

	A(int i = 0)  //类型转换构造函数 ，默认构造函数
	{
		val = i;
	}
	A& GetObj()   //返回对象
	{
		return *this;
	}
	//
};
int main() {
	A a;
	cout << a.val << endl;
	a.GetObj() = 5;
	cout << a.val << endl;
	return 0;
}