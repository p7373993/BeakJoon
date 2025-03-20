#include <iostream>
#include <vector>
using namespace std;

int main()
{
	
	int N, M;
	cin >>N >> M;
	int max = 0;
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}
	for (int i = 0; i < N-2; i++)
	{
		for (int j = i+1; j < N-1; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				if (max < (vec[i] + vec[j] + vec[k]) && (vec[i] + vec[j] + vec[k])<=M) max = (vec[i] + vec[j] + vec[k]);
			}
		}
	}
	cout << max;
}