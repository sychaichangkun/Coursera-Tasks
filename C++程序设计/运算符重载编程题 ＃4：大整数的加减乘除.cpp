
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


string& strReverse(string& str)
{
	int len = str.length();
	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return str;
}
string operator+(string s1, string s2)
{
	string result;
	bool carry = 0;
	int i = s1.length() - 1, j = s2.length() - 1;
	while (i >= 0 || j >= 0 || carry)
	{
		int res = (i >= 0 ? s1[i] - '0' : 0) + (j >= 0 ? s2[j] - '0' : 0) + carry;
		if (res >= 10)
		{
			res = res - 10; carry = 1;
		}
		else
			carry = 0;
		result += (char)('0' + res);
		i--;
		j--;
	}
	strReverse(result);
	if (result != "0") result = result.substr(result.find_first_not_of('0'));
	return result;
}

int stringcmp(string a, string b)
{

	if (a.length() > b.length()) return 1;
	if (a.length() == b.length()) return strcmp(a.c_str(), b.c_str());
	else return -1;
}

string operator-(string s1, string s2)
{
	string result;
	if (stringcmp(s1, s2) < 0)
	{
		result = '-';
		result += s2 - s1;

	}
	else if (stringcmp(s1, s2) == 0)
	{
		result = '0';
	}
	else//s1>s2
	{
		bool carry = 0;
		int i = s1.length() - 1, j = s2.length() - 1;
		while (i >= 0 || j >= 0 || carry)
		{
			int res = (i >= 0 ? s1[i] - '0' : 0) - (j >= 0 ? s2[j] - '0' : 0) - carry;
			if (res <0)
			{
				res = res + 10; carry = 1;
			}
			else
				carry = 0;
			result += (char)(res + '0');
			i--;
			j--;
		}
		strReverse(result);
		result = result.substr(result.find_first_not_of('0'));
	}
	if (result != "0") result = result.substr(result.find_first_not_of('0'));
	return result;
}

string operator*(string s1, string s2)
{
	if (s1 == "0" || s2 == "0")
		return "0";
	string result;
	string prod1 = s1;   //提前算好个位数 乘以s1的值
	string prod2 = s1 + s1;
	string prod3 = prod1 + prod2;
	string prod4 = prod1 + prod3;
	string prod5 = prod1 + prod4;
	string prod6 = prod1 + prod5;
	string prod7 = prod1 + prod6;
	string prod8 = prod1 + prod7;
	string prod9 = prod1 + prod8;
	for (int i = s2.length() - 1; i >= 0; i--)
	{
		string end;
		string zero = "0";
		string temp;
		for (int j = s2.length() - 1 - i; j > 0; j--)
			end.append(zero);
		switch (s2[i])
		{
		case '0':break;
		case '1':result = result + ((temp = prod1).append(end)); break;
		case '2':result = result + ((temp = prod2).append(end)); break;
		case '3':result = result + ((temp = prod3).append(end)); break;
		case '4':result = result + ((temp = prod4).append(end)); break;
		case '5':result = result + ((temp = prod5).append(end)); break;
		case '6':result = result + ((temp = prod6).append(end)); break;
		case '7':result = result + ((temp = prod7).append(end)); break;
		case '8':result = result + ((temp = prod8).append(end)); break;
		case '9':result = result + ((temp = prod9).append(end)); break;
		}
	}
	if (result != "0") result = result.substr(result.find_first_not_of('0'));
	return result;
}
string operator/(string s1, string s2)
{
	string result;
	if (stringcmp(s1, s2) < 0 || s1 == "0")
		result = '0';
	else if (stringcmp(s1, s2) == 0)
		result = '1';
	else  //s1>s2
	{
		int i = s2.length();//i为s1的从左往右第i个数
		string devidend = s1.substr(0, s2.length());
		while (i <= s1.length())//没超出s1的范围
		{
			string pos = "0";
			string respos;
			for (int j = 0; j <= 9; j++)
			{
				pos = '0' + j;
				if (stringcmp(devidend, s2*pos) >= 0)
					respos = pos;
				else
					break;
			}
			result.append(respos);
			devidend = devidend - s2*respos;
			devidend.append(s1.substr(i, 1));
			if (devidend.find_first_not_of('0') == string::npos) devidend = "0";
			else  devidend = devidend.substr(devidend.find_first_not_of('0'), string::npos);
			i++;
		}
	}
	if (result != "0") result = result.substr(result.find_first_not_of('0'));
	return result;
}

int main()
{
	string s1, s2;
	char oper;
	cin >> s1 >> oper >> s2;
	if (oper == '+')
		cout << s1 + s2 << endl;
	else if (oper == '-')
		cout << s1 - s2 << endl;
	else if (oper == '*')
		cout << s1 * s2 << endl;
	else if (oper == '/')
		cout << s1 / s2 << endl;

	return 0;
}