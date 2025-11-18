#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 10;
	while (n--)
	{
		int test;
		cin >> test;
		int arr[100][100];

		int mx = INT_MIN;

		for (int i = 0; i < 100; i++)
		{
			int sum = 0;
			for (int j = 0; j < 100; j++)
			{
				int tmp;
				cin >> tmp;
				arr[i][j] = tmp;
				sum += tmp;

			}
			mx = max(mx, sum);
		}

		int cross1 = 0, cross2 = 0;
		for (int j = 0; j < 100; j++)
		{
			int sum = 0;
			for (int i = 0; i < 100; i++)
			{
				sum += arr[i][j];
			}
			mx = max(mx, sum);

			cross1 += arr[j][j];
			cross2 += arr[j][99 - j];
		}
		mx = max(mx, max(cross1, cross2));
		cout << "#" << test << " " << mx << "\n";
	}
}