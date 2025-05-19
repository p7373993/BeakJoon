#include <iostream>
#include <vector>
#include <set>
//#include <algorithm>
using namespace std;

int n;
int mn = INT32_MAX;

vector <vector<int>> vec;
int a_people[21];
int b_people[21];
int find_mn(int a[])
{
	int sum = 0;
	for (int i = 1; i <= n ; i++)
	{
		if (a[i] == 1)
		{
			for (size_t j = i+1; j <= n; j++)
			{
				if (a[j] == 1)
				{
					sum += vec[i][j] + vec[j][i];
					
				}
			}
		}
	}
	return sum;
}
void back(int idx,int num)
{
	if (num > n / 2)
	{
		int a, b;
		a=find_mn(a_people);
		for (int i = 1; i <= n; i++)
		{
			b_people[i] = 0;
		}
		for (int i = 1; i <=n; i++)
		{
			if (a_people[i] == 0) b_people[i]=1;
		}
		b=find_mn(b_people);
		int c = a - b;
		if (c >= 0)
		{
			if (mn > c) mn = c;
		}
		else
		{
			if (mn > (-c)) mn = (-c);
		}
		return;
	}

	for (int i = idx; i <= n ; i++)
	{
		++a_people[i];
		back(i + 1 ,num+1);
		--a_people[i];

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector <vector<int>> vec2(n + 1, vector<int>(n + 1));

	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			cin>>vec2[i][j];
		}
	}
	vec = vec2;


	back(1,1);
	cout << mn;
}