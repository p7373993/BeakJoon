#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int M, N;
	bool bPrime = true;
	cin >> M >> N;
	vector<int> vec;
	for (int i = M; i <= N; i++)
	{
		if (i == 1) continue;
		bPrime = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				bPrime = false;
				break;
			}

		}
		if (bPrime) vec.push_back(i);
	}
	int result = 0;
	for (auto& v : vec)
	{
		result += v;
	}
	if (vec.empty())
	{
		cout << "-1";
		return 0;
	}
	else
	{
		cout << result << endl << vec[0];
	}
}