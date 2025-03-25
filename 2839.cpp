#include <iostream>

using namespace std;

int main()
{
	//5로 끝까지 뺴보고 그다음에 3으로도전
	int n,m;
	cin >> n;
	m = n;
	int a=0, b=0;
	int temp = n / 5;

	while (1)
	{
		n = m - 5 * temp;
		if (n % 3==0)
		{
			b = n / 3;
			a = temp;
			break;
		}
		if (temp <= 0)
		{
			cout << -1;
			return 0;
		}

		temp--;
	}
	cout << a + b;
}