#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int oper[4];
int num_min = INT32_MAX;
int num_max = INT32_MIN;
int n;

vector<int> vec;

void back(int idx,int total)
{
	if (n == idx)
	{
		num_min = min(num_min, total);
		num_max = max(num_max, total);
		return;
	}

	for (size_t i = 0; i < 4; i++)
	{
		if ( oper[i] != 0)
		{
			oper[i]--;
			switch (i)
			{
			case 0:
				back(idx + 1, total + vec[idx]);
				break;
			case 1:
				back(idx + 1, total - vec[idx]);
				break;
			case 2:
				back(idx + 1, total * vec[idx]);
				break;
			case 3:
				back(idx + 1, total / vec[idx]);
				break;
			}
			oper[i]++;

		}
		
	}

}
int main()
{
	cin >> n;
	int num;
	for (size_t i = 0; i < n; i++)
	{
		cin >> num;
		vec.emplace_back(num);
	}
	for (size_t i = 0; i < 4; i++)
	{
		cin >> num;
		oper[i] = num;
	}
	back(1,vec[0]);

	cout << num_max << "\n" << num_min;


}