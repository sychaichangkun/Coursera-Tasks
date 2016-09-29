//#include "stdafx.h"
#include <iostream>
using namespace std;
//f(n)=3f(n-2)+2f(n-4)+2f(n-6)+...+2f(2)+2f(0)
//f(2)=3 f(0)=1
int func(int n)  
{
	if (n % 2 == 1) return 0;
	if (n == 0) return 1;
	if (n == 2) return 3;
	return 4 * func(n - 2) - func(n - 4);
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == -1) break;
		cout << func(n) << endl;
	}
	//	system("pause");
	return 0;
}