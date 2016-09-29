#include <iostream>
#include <iomanip>
using namespace std;
// 在此处补充你的代码
int main()
{
	int num;
	cin >> num;
	cout << hex << num<<endl;
	cout << dec << setw(10) << setfill('0') << num << endl;
//	system("pause");
    return 0;
}