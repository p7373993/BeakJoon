#include <iostream>

using namespace std;

int main()
{
	//	f(n)=a1n+a0 ¡Â c*n
	// 0 <= (c-a1)n-a0
	// a0<=(c-a1)n0 ¾ç¼öÀÏ‹š
	//n>=n0
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	int result=0;
	if ((c - a1) > 0)
	{
		if (a0 <= (c - a1) * n0) result = 1;
	}
	else if ((c - a1) == 0)
	{
		if (a0 <= 0) result = 1;
	}

	cout << result;

}