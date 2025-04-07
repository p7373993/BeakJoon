#include <iostream>

using namespace std;

int main()
{

	long long int a, b;
	cin >> a >> b;
	long long int max = 0;
	long long int mul = 1;
	if (a > b) max = a;
	else max = b;
	for (long long int i = max; i >= 2; i--)
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
