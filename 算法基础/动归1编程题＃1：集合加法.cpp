//#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

int pairofs(int num, int *arr, int len, int sum)//某个数字和某一数组中元素 能够配对的个数
{
	int count = 0;
	for (; len > 0; len--)
	{
		if (arr[len - 1] + num == sum)
			count++;
	}
	return count;
}



int main()
{
	int n;
	cin >> n;

	for (; n > 0; n--) //n组数据
	{
		int sum, alen, blen, A[10000], B[10000], res = 0;
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		cin >> sum;//测试数据第一行
		cin >> alen;
		for (int i = 0; i < alen; i++)
		{
			cin >> A[i];
		}
		cin >> blen;//测试数据第四行
		for (int i = 0; i < blen; i++)
		{
			cin >> B[i];
		}

		for (int i = 0; i < alen; i++)//“我为人人”型递推
		{
			res += pairofs(A[i], B, blen, sum);
		}
		cout << res << endl;
	}

	//	system("pause");
	return 0;
}