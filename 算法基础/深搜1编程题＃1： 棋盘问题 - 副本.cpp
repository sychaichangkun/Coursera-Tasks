
#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
// 在此处补充你的代码
int n, k; //rows to fill    positions to fill
int posNum;//空位置个数
char *field = new char[64];
int C;//方案数目
bool* isTwice = new bool[8];//每一列上是否重复
bool DFS(int row, int pos)   //rows to fill    positions to fill
{
	if (row < pos || row<0)
		return false;
	if (pos == 0)
	{
		C++;
		return true;
	}



	for (int i = 0; i < n; i++)
	{
		//field[(8-row)*8+i]
		if (field[(n - row) * 8 + i] == '#' && isTwice[i] == false)
		{
			isTwice[i] = true;
			DFS(row - 1, pos - 1);
			isTwice[i] = false;
		}
	}
	DFS(row - 1, pos);
	return true;
}
int main()
{
	while (1)
	{
		cin >> n >> k;
		if (n == -1 && k == -1)
			break;
		memset(field, '0', sizeof(field));
		memset(isTwice, false, sizeof(isTwice));
		C = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> field[i * 8 + j];
			}
		}

		DFS(n, k);
		cout << C << endl;
	}

	return 0;
}