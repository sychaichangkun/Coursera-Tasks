#include <list>  
#include <iostream>  
#include <map> 
#include <string>
using namespace std;

class info
{
public:
	int idnum;
	int idnum1;
	int add;

};



int main()
{
	typedef map< int, list<int> > map_;
	int  num, n, m, p = 0, id1;
	string str;
	info A;
	map_ op;
	list<int>::iterator i;
	cin >> n;
	while (n--)
	{
		cin >> str;
		if (str == "new")
		{
			cin >> A.idnum;
			op.insert(map_::value_type(A.idnum, list<int>()));
		}
		else
			if (str == "add")
			{
				cin >> A.idnum >> A.add;
				op[A.idnum].push_back(A.add);
			}
			else
				if (str == "out")
				{
					cin >> A.idnum;
					op[A.idnum].sort();
					for (i = op[A.idnum].begin(); i != op[A.idnum].end(); i++)
					{
						cout << *i << " ";
					}
					cout << endl;
				}
				else
					if (str == "merge")
					{
						cin >> A.idnum >> A.idnum1;
						op[A.idnum].merge(op[A.idnum1]);
					}
					else
						if (str == "unique")
						{
							cin >> A.idnum;
							op[A.idnum].sort();
							op[A.idnum].unique();
						}
	}
	return 0;
}
