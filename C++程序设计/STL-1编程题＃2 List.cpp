
#include <iostream> 
#include <string>
#include <set> 
#include <map>
using namespace std;

class Solution
{
public:
	map<short, multiset<int> > mymap;

	void newid(short _id)
	{
		/*pair<int, multiset<int>> pair;*/
		/*	pair.first = _id;
		mymap.insert(pair);*/
		mymap[_id];
	}
	void add(short _id, short num)
	f{
		mymap[_id].insert(num);
	}
	void merge(short _id1, short _id2)
	{
		multiset<int>::const_iterator it = mymap[_id2].begin();
		while (it != mymap[_id2].end())
		{
			mymap[_id1].insert(*it);
			it++;
		}
		//		mymap.erase(_id2);
		mymap[_id2].clear();
	}
	void unique(short _id)
	{
		multiset<int>::iterator it = mymap[_id].begin();
		multiset<int>::iterator it2 = mymap[_id].begin();
		it2++;
		while (it2 != mymap[_id].end())
		{
			if (*it == *it2)
			{
				mymap[_id].erase(it2++);
			}
			else
			{
				it++;
				it2++;
			}
		}

	}
	void out(short _id)
	{
		multiset<int>::const_iterator it = mymap[_id].begin();
		while (it != mymap[_id].end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
};

int main() {
	Solution s;
	int cmdNum;
	cin >> cmdNum;
	for (; cmdNum > 0; cmdNum--)
	{
		string cmd;
		short input1, input2;
		cin >> cmd;
		if (cmd == "new")
		{
			cin >> input1;
			s.newid(input1);
		}
		else if (cmd == "add")
		{
			cin >> input1 >> input2;
			s.add(input1, input2);
		}
		else if (cmd == "merge")
		{
			cin >> input1 >> input2;
			s.merge(input1, input2);
		}
		else if (cmd == "unique")
		{
			cin >> input1;
			s.unique(input1);
		}
		else if (cmd == "out")
		{
			cin >> input1;
			s.out(input1);
		}
	}


//	system("pause");
	return 0;
}