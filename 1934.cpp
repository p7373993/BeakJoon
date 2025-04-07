#include <iostream>

using namespace std;

int main()
{

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		int max=0;
		int mul = 1;
		if (a > b) max = a;
		else max = b;
		for (int i = max; i >= 2; i--)
		{
			if (a % i == 0 && b % i == 0)
			{
				a /= i;
				b /= i;
				mul *= i;
			}
		}

		cout << a * b * mul << endl;
	}
}
