#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	int money,remain=0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> money;
		a = money / 25;
		remain = money % 25;
		b = remain / 10;
		remain = remain % 10;
		c = remain / 5;
		remain = remain % 5;
		d = remain;

		cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	}
}