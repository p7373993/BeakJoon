#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	int max;
	while (cin >> a >> b >> c)
	{
		if ((a == 0) && (b == 0) && (c == 0)) break;
		max = a;
		if (max < b) max = b;
		if (max < c) max = c;
		if (max<(a+b+c-max)) 
		{
			if ((a == b) && (a == c)) cout << "Equilateral" << endl;
			else if ((a == b) || (a == c) || (b == c))cout << "Isosceles" << endl;
			else cout << "Scalene"<<endl;
		}
		else 
		{
			cout << "Invalid" << endl;
		}
	}
}