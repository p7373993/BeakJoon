#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> vec;
	for (int i = 2; i < 1000000; i++)
	{
		bool out = false;
		if (i == 1) continue;

		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				out = true;
				break;
			}

		}
		if (!out)
		{
			vec.emplace_back(i);
		}
	}
	set<int> s(vec.begin(), vec.end());

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{ 
		int n;
		cin >> n;
		int num = 0;
		for (int j = 0; j <= vec.size(); j++)
		{
			if (vec[j] > (n / 2)) break;
			if (s.find(n - vec[j]) != s.end())
			{
				num++;
			}
		}
		cout << num<<endl;
	}
}
// n입력? 소수를 먼저 구하고 거기서 합구하기?
//아니면 2로 나눠서 거기에 존재하는 소수 구해서  n에 빼서 그 값이 소수인지 판단?
//#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> vec;
	for (int i = 2; i < 1000000; i++)
	{
		bool out = false;
		if (i == 1) continue;

		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				out = true;
				break;
			}

		}
		if (!out)
		{
			vec.emplace_back(i);
		}
	}
	set<int> s(vec.begin(), vec.end());

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{ 
		int n;
		cin >> n;
		int num = 0;
		for (int j = 0; j <= vec.size(); j++)
		{
			if (vec[j] > (n / 2)) break;
			if (s.find(n - vec[j]) != s.end())
			{
				num++;
			}
		}
		cout << num<<endl;
	}
}
// n입력? 소수를 먼저 구하고 거기서 합구하기?
//아니면 2로 나눠서 거기에 존재하는 소수 구해서  n에 빼서 그 값이 소수인지 판단?
//