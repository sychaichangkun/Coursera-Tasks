#include <iostream>
using namespace std;
// 在此处补充你的代码
#define Nmax 250
struct Sequence
{
	long long count;
	bool hasCount;
	Sequence(int _count = 0, bool _hasCount = false) :
		count(_count), hasCount(_hasCount) {}
};

Sequence seq[Nmax][Nmax];

long long getCount(int N, int K) //以K为首，和为N的回文式的数量
{
	if (seq[N][K].hasCount)
		return seq[N][K].count;

	if (N == K)
	{
		seq[N][K].hasCount = true;
		seq[N][K].count = 1;
		return 1;
	}
	if (N == 0)
	{
		seq[N][K].hasCount = true;
		seq[N][K].count = 1;
		return 1;
	}
	if (N - 2 * K < 0)
	{
		seq[N][K].hasCount = true;
		seq[N][K].count = 0;
		return 0;
	}
	if (N - 2 * K == 0)
	{
		seq[N][K].hasCount = true;
		seq[N][K].count = 1;
		return 1;
	}

	long long res = 0;
	for (long long i = K; i <= N - 2 * K; i++)
	{
		res += getCount(N - 2 * K, i);
	}
	seq[N][K].hasCount = true;
	seq[N][K].count = res;
	return res;
}

long long getCountofN(long long N)
{
	long long res = 0;
	for (long long i = 1; i <= N; i++)
	{
		res += getCount(N, i);
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	while (N != 0)
	{
		cout << N << " " << getCountofN(N) << endl;
		cin >> N;
	}


	return 0;
}