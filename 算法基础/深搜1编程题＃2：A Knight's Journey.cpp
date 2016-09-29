
#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
// 在此处补充你的代码
int p,q; //1...p     A...q
int x, y;//当前的位置
bool *field = new char[64];
bool DFS(int xstart,int ystart,int pos2fill) 
{
	if (pos2fill <= 0)
		return true;
	if (available(x - 1, y - 2))
	{
		field[x*p + y] = true;
		if(DFS(xstart, ystart, pos2fill - 1)==false)
			field[x*p + y] = false;
	}
	if (available(x - 1, y + 2))
	{
		field[x*p + y] = true;
		if (DFS(xstart, ystart, pos2fill - 1) == false)
			field[x*p + y] = false;
	}
	if (available(x + 1, y - 2))
	{
		field[x*p + y] = true;
		if (DFS(xstart, ystart, pos2fill - 1) == false)
			field[x*p + y] = false;
	}
	if (available(x - 1, y - 2))
	{
		field[x*p + y] = true;
		if (DFS(xstart, ystart, pos2fill - 1) == false)
			field[x*p + y] = false;
	}
}

bool available(int x, int y)
{
	if (x<0 || x>p-1|| y<0 || y>q - 1)
		return false;
	if (field[x*p + y] == true)
		return false;
	else 
		return true;
}

int main()
{
	
	memset(field,false,sizeof(field));

	return 0;
}