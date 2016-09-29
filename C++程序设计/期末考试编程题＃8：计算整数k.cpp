
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	unsigned int t, i, j, n, res;
	cin >> t;
	for (; t > 0; t--)
	{
		cin >> n >> i >> j;
		unsigned int tempj = 1, tempi = 1;
		res = (1 << (j + 1));
		tempj = (1 << j);
		res = res - (1 << (i));
		tempi = (1 << i);

		if ((n&tempj) == tempj) //n的第j位为1
			res = res - tempj;
		if ((n&tempi) != tempi)   //n的第i位为0
			res = res - tempi;

		cout << hex << res<<endl;
	}

	return 0;
}