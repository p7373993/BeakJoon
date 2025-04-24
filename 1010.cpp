#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;

		cin >> k >> n;
		int sum = 1;
		for (int i = 0; i < k; i++)
		{
			sum *= (n - i);
			sum /= (i + 1);
		}
		cout << sum << "\n";
	}
}