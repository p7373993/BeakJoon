#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	string row;
	string row1 = "WBWBWBWB";
	string row2 = "BWBWBWBW";
	vector<string> vec;
	vector<string> ex1;
	vector<string> ex2;
	int min = 2501,num1=0,num2=0;
	for (int i = 0; i < N; i++)
	{
		cin >> row;
		vec.push_back(row);
	}
	
	for (int i = 0; i < 4; i++)
	{
		ex1.push_back(row1);
		ex1.push_back(row2);
		ex2.push_back(row2);
		ex2.push_back(row1);
	}
	for (int i = 0; i <= N-8; i++)
	{
		for (int k = 0; k <= M-8; k++)
		{
			num1 = 0;
			num2 = 0;
			for (int j = i; j < i + 8; j++)
			{
				for (int g = k; g < k + 8; g++)
				{
					if (ex1[j - i][g - k] != vec[j][g]) num1++;
					if (ex2[j - i][g - k] != vec[j][g]) num2++;
				}
			}
			if (min > num1) min = num1;
			if (min > num2) min = num2;

		}
	}
	cout << min;
	return 0;
}