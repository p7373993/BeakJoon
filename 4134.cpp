#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long int a;
		cin >> a;
		if (a == 1||a==0)
		{
			cout << 2<<endl;
			continue;
		}
		while (1)
		{
			bool out = true;
			for (long long int j = 2; j*j <= a; j++)
			{
				if (a % j == 0)
				{
					a++;
					out = false;
					break;
				}
			}
			if (out)
			{
				cout << a << endl;
				break;
			}
		}

	}
}

//235711 >>앞선 소수를 가지고 판단?