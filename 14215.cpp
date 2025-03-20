#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin>> a >> b >> c;
	int max = a;
	int temp;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max >= (a + b+c-max))
	{
		temp = (a + b + c - max) - 1;
		cout << (temp + (a + b + c - max));
		return 0;
	}
	else
	{
		cout << (a + b + c);
		return 0;
	}

}