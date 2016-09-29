#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2
{
private:
	int row;	//行数
	int col;	//列数
	int* nums;
public:
	int getSize() { return row*col; }
	Array2(int r = 0, int c = 0) :row(r), col(c)
	{
		if (r*c == 0)
			nums = NULL;
		else
		{
			nums = new int[r*c];
		}
	}
	int* operator[](int i)
	{
		return nums + col*i;
	}
	int& operator()(int i, int j)
	{
		return *(nums + i*col + j);
	}
	Array2& operator=(Array2& arr)
	{
		if (!nums) delete[]nums;
		if (arr.nums)
		{
			nums = new int[arr.getSize()];
			int* p = nums, *q = arr.nums;
			for (int i = 0; i < arr.getSize(); i++)
				*(p++) = *(arr.nums++);
			row = arr.row;
			col = arr.col;
		}
		else nums = NULL;
		return *this;
	}
};




int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;     b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}