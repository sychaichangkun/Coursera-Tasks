
#include <iostream>
#include <iomanip>
using namespace std;
// 在此处补充你的代码
int main()
{
	double num;
	cin >> num;
	cout << setiosflags(ios::fixed) << setprecision(5) << num << endl <<
		resetiosflags(ios::fixed) << setiosflags(ios::scientific)
		<< setprecision(7) << num << endl;
	return 0;
}