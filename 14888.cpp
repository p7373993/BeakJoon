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
vector<int> vec(n);

int find_max()
{
	int temp = total;
	int a_temp[4];
	copy(oper, oper + 4, a_temp);
	
	for (size_t i = 0; i < n; i++)
	{
		if (a_temp[0] != 0)
		{

		}
	}
}
int find_min()
{

}
vector<int> possible()
{
	vector<int> temp;
	for (size_t i = 0; i < 4; i++)
	{
		if (oper[i] != 0)
		{
			temp.emplace_back(i);
		}
	}
	return temp;

}
void back(int idx)
{
	if ((n - 1) == idx)
	{
		if (total > num_max) num_max = total;
		if (total < num_min) num_min = total;
		return;
	}
	vector<int> pos;
	num = vec[idx];
	pos = possible();
	for (auto& v : pos)
	{
		int temp = total;
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
		back(idx + 1);

		total = temp;
		oper[v]++;
	}

}
int main()
{
	cin >> n;
	
	for (size_t i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	for (size_t i = 0; i < 4; i++)
	{
		int num;
		cin >> num;
		oper[i] = num;
	}
	total = vec[0];
	num_max = find_max();
	back(1);
}