//#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


struct Area
{
	int hight;
	int dist;
	Area(int _hight = -1, int _dist = 0) :hight(_hight), dist(_dist) {}
};

bool mysort(Area *a, Area *b)//按照Area的高度由小到大排列
{
	return a->hight < b->hight;
}

int max(Area *a, Area *b, Area *c, Area *d, Area *self)
{
	int maxdist = self->dist;
	if (a->dist >= maxdist&&a->hight<self->hight) maxdist = a->dist + 1;
	if (b->dist >= maxdist&&b->hight<self->hight) maxdist = b->dist + 1;
	if (c->dist >= maxdist&&c->hight<self->hight) maxdist = c->dist + 1;
	if (d->dist >= maxdist&&d->hight<self->hight) maxdist = d->dist + 1;
	return maxdist;
}
int main()
{
	int R, C;
	cin >> R >> C;
	Area area[102][102];
	for (int i = 1; i < R + 1; i++)
		for (int j = 1; j < C + 1; j++)
		{
			cin >> area[i][j].hight;
			area[i][j].dist = 1;
		}
	//初始化数组


	Area *pArea[102 * 102];
	for (int i = 0; i < 102 * 102; i++)
	{
		pArea[i] = ((Area*)area) + i;
	}
	sort(pArea, pArea + 102 * 102, mysort);//对指针数组进行排序
										   //排列数组

	int maxdist = 0;
	for (int i = 0; i < 102 * 102; i++)
	{
		Area *p = pArea[i];
		if (p->hight < 0) continue;
		p->dist = max(p - 102, p + 1, p - 1, p + 102, p);
		if (p->dist > maxdist)
			maxdist = p->dist;
	}
	//“我为人人”递推

	cout << maxdist << endl;
//	system("pause");
	return 0;
}