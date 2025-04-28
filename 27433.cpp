#include <iostream>

using namespace std;

long long fac(long long int a)
{
	if (a <= 1) return 1;
	return a * fac(a - 1);
}

int main()
{
	int n;
	cin >> n;
	cout << fac(n);
}