#include <stdio.h>
#include <string.h>
// 在此处补充你的代码
#define Nmax 3402
#define Mmax 12880

unsigned result[Mmax + 1];
struct Charm
{
	int w;
	int d;
	//	Charm(int weight, int desire) :w(weight), d(desire) {}
}charms[Nmax];

unsigned int Dmax(int k, int w)
{
	for (int i = 0; i < k + 1; i++)
		for (int j = w; j >= charms[i].w&&w - charms[i].w >= 0; j--)
			if (result[j] < result[j - charms[i].w] + charms[i].d)
				result[j] = result[j - charms[i].w] + charms[i].d;
	return result[w];
}
int main()
{
	memset(result, 0, sizeof(result));
	unsigned int N, M;
	scanf("%d%d", &N, &M);
	for (unsigned int i = 0; i < N; i++)
	{
		scanf("%d%d", &charms[i].w, &charms[i].d);
	}
	printf("%d", Dmax(N, M));

	return 0;
}