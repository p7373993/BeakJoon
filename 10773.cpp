#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> vec(n);
	int index = 0;
	int in;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		if (in == 0) --index;
		else
		{
			vec[index++] = in;
		}
	}

	int sum = 0;
	for (int i = 0; i < index; i++)
	{
		sum += vec[i];
	}
	cout << sum;
}