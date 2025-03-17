#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int a;
	vector<vector<int>> array1(N);
	vector<vector<int>> array2(N);
	vector<vector<int>> array3(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a;
			array1[i].push_back(a);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a;
			array2[i].push_back(a);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			a= array1[i][j]+ array2[i][j];
			array3[i].push_back(a);
		}
	}
	for (auto& ex1 : array3)
	{
		for (auto& ex2 : ex1)
		{
			cout << ex2 << ' ';
		}
		cout << endl;
	}
	return 0;
}