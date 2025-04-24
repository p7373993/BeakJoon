#include <iostream>

using namespace std;

int pac(int k)
{
	int sum = 1;
	for (int i = 1; i <= k; i++)
	{
		sum *= i;
	}
	return sum;
}
int main()
{
	int n, k;

	cin >> n >> k;

	cout << pac(n) / (pac(n - k) * pac(k));
}