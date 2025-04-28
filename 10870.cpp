#include <iostream>

using namespace std;

long long pibo(int n)
{
	if (n <= 1) return n;
	return pibo(n - 1) + pibo(n - 2);
}
int main()
{
	int n;
	cin >> n;
	cout << pibo(n);
}