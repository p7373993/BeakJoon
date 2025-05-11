#include <iostream>
#include <vector>
#include <set>
//#include <algorithm>
using namespace std;

int n;
int mn = INT32_MAX;
set<int> a_people;//차집합으로 나머지 b에 
set<int> all_people;
set<int> b_people;
vector <vector<int>> vec;
int find_mn()
{
	vector<int> temp_a(a_people.begin(), a_people.end());
	vector<int> temp_b(b_people.begin(), b_people.end());

	vector<pair<int,int>> pair_a;
	vector<pair<int, int>> pair_b;

	for (size_t i = 0; i < n/2; i++)
	{
		for (size_t j = i+1; j < n/2; j++)
		{
			pair_a.push_back({temp_a[i],temp_a[j]});
			pair_a.push_back({temp_a[j],temp_a[i]});


			pair_b.push_back({ temp_b[i],temp_b[j] });
			pair_b.push_back({ temp_b[j],temp_b[i] });

		}
	}
	int a_num=0, b_num=0;
	for (auto& [first, second] : pair_a)
	{
		a_num = a_num + vec[first][second];
	}
	for (auto& [first, second] : pair_b)
	{
		b_num = b_num + vec[first][second];
	}

	if (a_num > b_num) return a_num - b_num;
	else return b_num - a_num;
}
void back()
{
	if (a_people.size() == n / 2)
	{
		b_people = all_people;
		for (auto& a : a_people)
		{
			b_people.erase(a);
		}
		int temp = find_mn();

		if (mn > temp) mn = temp;
		return;
	}

	for (int i = 1; i <= n ; i++)
	{
		if (a_people.find(i) == a_people.end())
		{
			a_people.insert(i);
			back();
			a_people.erase(i);
		}
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
	for (int i = 1; i <= n; i++)
	{
		all_people.insert(i);
	}

	back();
	cout << mn;
}