#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		int n;
		cin >> n;

		vector<string> vec(n);
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
		}
		int start = 0;
		int end = n;
		int half = n / 2;
		int sum = 0;
		while (half--)
		{
			start++;
			end--;
			for (int i = start; i < end; i++)
			{
				sum += vec[half][i]-'0';
			}

		}
		start = 0;
		end = n;
		half = n / 2;
		while (half< n)
		{

			for (int i = start; i < end; i++)
			{
				sum += vec[half][i]-'0';
			}
			start++;
			end--;
			half++;
		}

		cout << "#" << test+1 << " " << sum<<"\n";
	}
}