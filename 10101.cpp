#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	string result;
	((a + b + c) != 180) ? result = "Error" : ((a!=b)&&(a!=c)&&(b!=c)) ? result = "Scalene" : ((a == b) && (a == c) && (b == c))?result = "Equilateral": result= "Isosceles";

	cout << result;
}