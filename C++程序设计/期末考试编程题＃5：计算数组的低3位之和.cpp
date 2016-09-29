//#include "stdafx.h"
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
// 在此处补充你的代码
class CMy_add
{
public:
	int &sum;
	CMy_add(int &num) :sum(num) {}
	int operator()(int n)
	{
		sum += n % 8;
		return sum;
	}
};
/*
int main(int argc, char* argv[]) {
int v, my_sum = 0;
vector<int> vec;
cin >> v;
while (v) {
vec.push_back(v);
cin >> v;
}
for_each(vec.begin(), vec.end(), CMy_add(my_sum));
cout << my_sum << endl;


return 0;
}*/