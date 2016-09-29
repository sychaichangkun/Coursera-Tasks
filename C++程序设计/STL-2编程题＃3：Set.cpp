#include <iostream>
#include <string>
#include <set>
using namespace std;

template <class T>
class Myset
{
public:
	set<T> myset2;
	multiset<T> myset;
	void add(T elem)
	{
		myset.insert(elem);
		myset2.insert(elem);
		cout << myset.count(elem) << endl;
	}
	void del(T elem)
	{
		int num = myset.count(elem);
		myset.erase(elem);
		cout << num << endl;
	}
	void ask(T elem)
	{
		cout << (myset2.count(elem) ? 1 : 0) << " " << myset.count(elem) << endl;
	}
};

int main()
{
	Myset<int> mset;
	int cmdNum = 0;
	string cmd;
	cin >> cmdNum;
	for (; cmdNum > 0; cmdNum--)
	{
		cin >> cmd;
		if (cmd == "add")
		{
			int num;
			cin >> num;
			mset.add(num);
		}
		else if (cmd == "ask")
		{
			int num;
			cin >> num;
			mset.ask(num);
		}
		else if (cmd == "del")
		{
			int num;
			cin >> num;
			mset.del(num);
		}
	}
	return 0;
}