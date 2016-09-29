#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Student
{
public:
	void getInfo()
	{
		string info;
		stringstream ss;
		cin >> info;

		name = info.substr(0, info.find_first_of(','));//name
		info = info.substr(info.find_first_of(',') + 1);

		ss << info.substr(0, info.find_first_of(','));//age
		ss >> age;
		info = info.substr(info.find_first_of(',') + 1);
		ss.clear();//每次用完stringstream要记得clear

		ID = info.substr(0, info.find_first_of(','));//ID
		info = info.substr(info.find_first_of(',') + 1);

		ss << info.substr(0, info.find_first_of(','));//score1
		ss >> score1;
		info = info.substr(info.find_first_of(',') + 1);
		ss.clear();

		ss << info.substr(0, info.find_first_of(','));//score2
		ss >> score2;
		info = info.substr(info.find_first_of(',') + 1);
		ss.clear();

		ss << info.substr(0, info.find_first_of(','));//score3
		ss >> score3;
		info = info.substr(info.find_first_of(',') + 1);
		ss.clear();

		ss << info;//score4
		ss >> score4;
		ss.clear();
	}
	void printInfo()
	{
		cout << name << "," << age << "," << ID << ","
			<< (score1 + score2 + score3 + score4) / 4 << endl;
	}
private:
	string name;
	int age;
	string ID;
	int score1;
	int score2;
	int score3;
	int score4;
};



int main() {
	Student x;
	x.getInfo();
	x.printInfo();

	return 0;
}
