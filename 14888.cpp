#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int oper[4];
int num_min;
int num_max;
int n;
int num;
int total;
vector<int> vec;

int find_first()
{
	int temp = vec[0];
	int a_temp[4];
	copy(oper, oper + 4, a_temp);
	
	for (size_t i = 1; i < n; i++)
	{
		if (a_temp[0] != 0)
		{
			temp = temp + vec[i];
			a_temp[0]--;
		}
		else if(a_temp[1]!=0)
		{
			temp = temp - vec[i];
			a_temp[1]--;
		}
		else if (a_temp[2] != 0)
		{
			temp = temp * vec[i];
			a_temp[2]--;
		}
		else if (a_temp[3] != 0)
		{
			temp = temp / vec[i];
			a_temp[3]--;
		}
	}
	return temp;
}

vector<int> possible()
{
	vector<int> temp;
	for (size_t i = 0; i < 4; i++)
	{
		
		for (size_t j = 0; j < oper[i]; j++)
		{
			temp.emplace_back(i);
		}
	}
	return temp;

}
void back(int idx)
{
	if (n == idx)
	{
		if (total > num_max) num_max = total;
		if (total < num_min) num_min = total;
		return;
	}
	vector<int> pos;
	pos = possible();
	for (auto& v : pos)
	{
		int temp = total;
		num = vec[idx];

		switch (v)
		{
		case 0:
			total = total + num;
			break;

		case 1:
			total = total - num;
			break;

		case 2:
			total = total * num;
			break;

		case 3:
			total = total / num;
			break;

		default:
			break;
		}
		oper[v]--;
		back(idx + 1);

		total = temp;
		oper[v]++;
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
		int num;
		cin >> num;
		oper[i] = num;
	}
	total = vec[0];
	num_max = num_min = find_first();
	back(1);

	cout << num_max << "\n" << num_min;


}