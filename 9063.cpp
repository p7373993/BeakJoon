#include <iostream>

using namespace std;

int main()
{
	int n;
	int x1=10000, y1=10000,x2=-10000,y2=-10000;
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if(x1 > x) x1 = x;
		if(x2 < x) x2 = x;
		if(y1 > y) y1 = y;
		if(y2 < y) y2 = y;
	}

	cout << (x2 - x1) * (y2 - y1);
}