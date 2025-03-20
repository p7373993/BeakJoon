#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> vec;
	while (1)
	{
		if (N == 1) break;
		for (int i = 2; i <= N; i++)
		{
			if (N % i == 0) {
				vec.push_back(i);
				N /= i;
				break;
			}
		}
	}
	for (auto& v : vec)
	{
		cout << v << endl;
	}
}