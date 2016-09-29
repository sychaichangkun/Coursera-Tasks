
#include <iostream>
#include <string.h>
using namespace std;
// 在此处补充你的代码
bool seq[300];
int main()
{
	memset(seq, false, sizeof(seq));
	int m, n;
	cin >> n >> m;
	memset(seq, true, n);
	int i = n;

	int count = 0;
	for (int j = 0; j < n; )
	{
		if (i == 1) break;
		if (seq[j] == true) count++;
		if (count == m)
		{
			seq[j] = false;
			i--;
			count = 0;
		}
		j++;
		if (j == n)
			j = 0;
	}
	for (int j = 0; j < n; j++)
	{
		if (seq[j] == true)
			cout << j + 1 << endl;
	}


	return 0;
}