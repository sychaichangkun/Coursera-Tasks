#include <iostream>
using namespace std;

int main()
{
	int s1, s2, s3, s4, s5, s6, s7, s8, s9;//1-9种移动，每种移动的个数，用来枚举
	int step[9] = { 0 };
	int minstep = 100000;
	int a, b, c, d, e, f, g, h, i;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
	for (s1 = 0; s1 < 4; s1++)
		for (s2 = 0; s2 < 4; s2++)
			for (s3 = 0; s3 < 4; s3++)
				for (s4 = 0; s4 < 4; s4++)
					for (s5 = 0; s5 < 4; s5++)
						for (s6 = 0; s6 < 4; s6++)
							for (s7 = 0; s7 < 4; s7++)
								for (s8 = 0; s8 < 4; s8++)
									for (s9 = 0; s9 < 4; s9++)
									{
										if ((s1 + s2 + s4 + a) % 4 == 0 && (s1 + s2 + s3 + s5 + b) % 4 == 0 && (s2 + s3 + s6 + c) % 4 == 0
											&& (s1 + s4 + s5 + s7 + d) % 4 == 0 && (s1 + s3 + s5 + s7 + s9 + e) % 4 == 0 && (s3 + s5 + s6 + s9 + f) % 4 == 0
											&& (s4 + s7 + s8 + g) % 4 == 0 && (s5 + s7 + s8 + s9 + h) % 4 == 0 && (s6 + s8 + s9 + i) % 4 == 0)
											if (minstep>s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + s9)
											{
												minstep = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + s9;
												step[0] = s1; step[1] = s2; step[2] = s3; step[3] = s4;
												step[4] = s5; step[5] = s6; step[6] = s7; step[7] = s8;
												step[8] = s9;
											}

									}

	for (int i = 0; i < 9; i++)
	{
		while (step[i]--)
		{
			cout << i + 1 << " ";
		}
	}
	//	system("pause");
	return 0;

}