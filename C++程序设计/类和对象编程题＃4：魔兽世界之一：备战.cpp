// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


enum force { DRAGON = 0, NINJA = 1, ICEMAN = 2, LION = 3, WOLF = 4 };
int redorder[5] = { 2,3,4,1,0 };
int blueorder[5] = { 3,0,1,2,4 };


class Forceman
{
public:
	int hp;
	int num;
	int atk;
	bool addable;
	string name;
};
class Dragon :public Forceman
{
public:
	Dragon()
	{
		addable = true;
		num = 0;
		name = "dragon";
	}
	void addDragon() { num++; }
	void setHP(int x) { hp = x; }
};
class Ninja :public Forceman
{
public:
	Ninja()
	{
		addable = true;
		num = 0;
		name = "ninja";
	}
	void addNinja() { num++; }
	void setHP(int x) { hp = x; }
};
class Iceman :public Forceman
{
public:
	Iceman()
	{
		addable = true;
		num = 0;
		name = "iceman";
	}
	void addIceman() { num++; }
	void setHP(int x) { hp = x; }
};
class Lion :public Forceman
{
public:
	Lion()
	{
		addable = true;
		num = 0;
		name = "lion";
	}
	void addLion() { num++; }
	void setHP(int x) { hp = x; }
};
class Wolf :public Forceman
{
public:
	Wolf()
	{
		addable = true;
		num = 0;
		name = "wolf";
	}
	void addWolf() { num++; }
	void setHP(int x) { hp = x; }
};

class Headquarter
{

public:
	static int gametime;
	int health;
	string color;
	int forceNum;
	bool isStop;
	Dragon dragon;
	Ninja ninja;
	Iceman iceman;
	Lion lion;
	Wolf wolf;
	Headquarter(int h, string _color) :health(h), color(_color), forceNum(0), isStop(false) {}
	int setHealth(int _health)
	{
		health = _health;
		return health;
	}
	string getColor()
	{
		return color;
	}
	void checkaddable()
	{
		if (dragon.hp <= health) dragon.addable = true;
		else dragon.addable = false;
		if (ninja.hp <= health) ninja.addable = true;
		else ninja.addable = false;
		if (iceman.hp <= health) iceman.addable = true;
		else iceman.addable = false;
		if (lion.hp <= health) lion.addable = true;
		else lion.addable = false;
		if (wolf.hp <= health) wolf.addable = true;
		else wolf.addable = false;
	}
	bool addForce(force f)
	{
		checkaddable();

		if (isStop == false && (dragon.addable || ninja.addable || iceman.addable || lion.addable || wolf.addable) == false)
		{
			isStop = true;
			cout << setw(3) << setfill('0') << gametime << " ";
			cout << color << " " << "headquarter stops making warriors" << endl;
			return true;
		}


		if (f == DRAGON&&dragon.addable == true)
		{
			dragon.addDragon();
			setHealth(health - dragon.hp);
			forceNum++;
			printInfo(f);
			return true;

		}
		else if (f == NINJA&&ninja.addable == true)
		{
			ninja.addNinja();
			setHealth(health - ninja.hp);
			forceNum++;
			printInfo(f);
			return true;

		}
		else if (f == ICEMAN&&iceman.addable == true)
		{
			iceman.addIceman();
			setHealth(health - iceman.hp);
			forceNum++;
			printInfo(f);
			return true;

		}
		else if (f == LION&&lion.addable == true)
		{
			lion.addLion();
			setHealth(health - lion.hp);
			forceNum++;
			printInfo(f);
			return true;

		}
		else if (f == WOLF&&wolf.addable == true)
		{
			wolf.addWolf();
			setHealth(health - wolf.hp);
			forceNum++;
			printInfo(f);
			return true;

		}

		return false;
	}
	void printInfo(force f)
	{


		switch (f)
		{
		case DRAGON:
			cout << setw(3) << setfill('0') << gametime << " ";
			cout << color << " dragon "
				<< forceNum << " born with strength " << dragon.hp << "," << dragon.num
				<< " dragon in " << color << " headquarter" << endl;
			break;
		case NINJA:
			cout << setw(3) << setfill('0') << gametime << " ";
			cout << color << " ninja "
				<< forceNum << " born with strength " << ninja.hp << "," << ninja.num
				<< " ninja in " << color << " headquarter" << endl;
			break;
		case LION:
			cout << setw(3) << setfill('0') << gametime << " ";
			cout << color << " lion "
				<< forceNum << " born with strength " << lion.hp << "," << lion.num
				<< " lion in " << color << " headquarter" << endl;
			break;
		case ICEMAN:
			cout << setw(3) << setfill('0') << gametime << " ";
			cout << color << " iceman "
				<< forceNum << " born with strength " << iceman.hp << "," << iceman.num
				<< " iceman in " << color << " headquarter" << endl;
			break;
		case WOLF:
			cout << setw(3) << setfill('0') << gametime << " ";
			cout << color << " wolf "
				<< forceNum << " born with strength " << wolf.hp << "," << wolf.num
				<< " wolf in " << color << " headquarter" << endl;
		}
	}

};
int Headquarter::gametime = 0;



int main()
{


	int testnum, M;

	cin >> testnum;

	for (int testTime = 1; testTime <= testnum; testTime++)
	{

		cin >> M;
		Headquarter h1(M, "red");
		Headquarter h2(M, "blue");
		Headquarter::gametime = 0;
		int hp1, hp2, hp3, hp4, hp5;
		cin >> hp1 >> hp2 >> hp3 >> hp4 >> hp5;
		cout << "Case:" << testTime << endl;
		h1.dragon.setHP(hp1);
		h2.dragon.setHP(hp1);
		h1.ninja.setHP(hp2);
		h2.ninja.setHP(hp2);
		h1.iceman.setHP(hp3);
		h2.iceman.setHP(hp3);
		h1.lion.setHP(hp4);
		h2.lion.setHP(hp4);
		h1.wolf.setHP(hp5);
		h2.wolf.setHP(hp5);


		int orderblue = 0;
		int orderred = 0;
		while (h1.isStop == false || h2.isStop == false)
		{
			if (orderred == 5) orderred = 0;
			if (orderblue == 5) orderblue = 0;

			while (!h1.addForce((force)redorder[orderred++]) && h1.isStop == false)
			{
				if (orderred == 5) orderred = 0;

			}
			while (!h2.addForce((force)blueorder[orderblue++]) && h2.isStop == false)
			{
				if (orderblue == 5) orderblue = 0;
			}


			//		if (h1.isStop == true&&h2.isStop == true) break;
			Headquarter::gametime++;

		}



	}

	return 0;
}
