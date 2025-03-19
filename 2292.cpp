#include <iostream>

using namespace std;
//1 7 19 37 61
//6 12 18 24
//1 2 3 4 
int main()
{
	long long n;
	int ex=1;
	cin >> n;
	if (n == 1) {
		cout << 1; return 0;
	}
	for (int i = 0; 1; i++)
	{
		if (n <= ex) {
			cout << i ;
			break;
		}
		ex += 6 * i;
	}
}