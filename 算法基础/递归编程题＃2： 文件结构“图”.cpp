//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class File
{
public:
	int level;//层数
	string name;
	File(string _name, int _level) :name(_name), level(_level) {}
	void printLevel()
	{
		for (int i = 0; i < level; i++)
		{
			cout << "|     ";
		}
		cout << name << endl;
	}
	//bool operator<(const File* f)
	//{
	//	return strcmp(this->name.c_str(), f->name.c_str());
	//}
};

bool less_files(const File* f1, const File* f2)
{
	int res = strcmp(f1->name.c_str(), f2->name.c_str());
	return res < 0 ? true : false;
}

class Dir
{
public:
	int level;
	string name;
	vector<Dir*> dirs;
	vector<File*> files;
	Dir* parent;
	Dir(string _name, Dir* _p, int _level) :name(_name), parent(_p), level(_level) {}
	void sortFiles()
	{
		if (!files.empty()) sort(files.begin(), files.end(), less_files);
		for (unsigned int i = 0; i < dirs.size(); i++)
			dirs[i]->sortFiles();
	}
	void printLevel()
	{
		for (int i = 0; i < level; i++)
		{
			cout << "|     ";
		}
		cout << name << endl;
		for (unsigned int i = 0; i < dirs.size(); i++)
			dirs[i]->printLevel();
		for (unsigned int i = 0; i < files.size(); i++)
			files[i]->printLevel();
	}
};


int main()
{

	int caseNum = 0;
	while (1)
	{
		Dir* root = new Dir("ROOT", NULL, 0);
		Dir* curDir = root;
		string str;
		while (cin >> str)
		{
			if (str == "#")
				return 0;
			else if (str == "*")
			{
				if (caseNum) cout << endl; //如果不是第一行 则输出一空行
				caseNum++;
				cout << "DATA SET " << caseNum << ":" << endl;
				root->sortFiles();
				root->printLevel();
				break;
			}
			else if (str[0] == 'f')
				curDir->files.push_back(new File(str, curDir->level));
			else if (str[0] == 'd')
			{
				curDir->dirs.push_back(new Dir(str, curDir, curDir->level + 1));
				curDir = curDir->dirs.back();
			}
			else if (str[0] == ']')
			{
				curDir = curDir->parent;
			}
		}

	}



//	system("pause");
	return 0;
}