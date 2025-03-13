#include <iostream>

using namespace std;

int main() {
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		for (int j = 1; j<(a - i); j++)
		{
			cout << " ";
		}
		//2n +1 
		for (int j = 0;j<i*2+1; j++)
		{
			cout << "*";
		}
	cout <<endl;

	}
	for (int i = a-2; i >=0; i--)
	{
		for (int j = 1; j < (a - i); j++)
		{
			cout << " ";
		}
		//2n +1 
		for (int j = 0; j < i * 2 + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
