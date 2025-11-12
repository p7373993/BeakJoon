#include <iostream>
#include <vector>

using namespace std;
//2로 나눠서 그걸로 8의 갯수 구하고 나머지 1은 0 또는 4넣기
//3 > 80,48
//5 >880,488, 808, 그냥 무조건 4,8인듯? 
int main()
{
	int arr[10] = { 1, 0, 0, 0, 1, 0, 1, 0, 2, 1 };

	int x;
	cin >> x;
	long long result = 0;
	if (x == 1)
	{
		cout << result;
		return 0;
	}

	int v, r;
	v = x / 2;
	r = x % 2;
	if (r == 1)
	{
		result = 4;
		for (size_t i = 0; i < v; i++)
		{
			result = result * 10 + 8;
		}
	}
	else
	{
		result = 8;
		for (size_t i = 1; i < v; i++)
		{
			result = result * 10 + 8;
		}
	}

	cout << result;
	return 0;

}