#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int max1, max2;

	if (a > b) max1 = a;
	else max1 = b;

	if (c > d) max2 = c;
	else max2 = d;

	for (int i = max1; i >= 2; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			a /= i;
			b /= i;
		}
		if (c % i == 0 && d % i == 0)
		{
			c /= i;
			d /= i;
		}
	}
	int top = (b * c) + (a * d);
	int bottom = (b * d);
	if (top > bottom) max1 = top;
	else max1 = bottom;

	int min;
	if (top > bottom) min = bottom;
	else min = top;

	int i = 2;
	while (i<=min)
	{
		if (top % i == 0 && bottom % i == 0)
		{
			top /= i;
			bottom /= i;
			min /= i;
			i = 2;
			continue;
		}
		i++;
	}
	cout << top << " " << bottom;
}


// 3/4  1/6>>22/24>11/12