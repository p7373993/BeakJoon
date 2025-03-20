#include <iostream>

using namespace std;

int main()
{
	int n, k,result;
	cin >> n >> k;
	int temp = 0;
	for (int i = 1; i < n+1; i++)
	{
		if (n % i == 0)
		{
			temp++;
			if (temp == k) { result = i; break; }
			else result = 0;
		}
	}

	cout << result;
}


