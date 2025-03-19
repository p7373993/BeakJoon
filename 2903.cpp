#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//0 1 2 3 4 5
	//1 2 4 8 16 32
	//2 3 5 9 17 33

	int n;
	cin >> n;
	long long result;
	result = pow(pow(2, n) + 1, 2);
	cout << result;
}