//nCk? �̰� �ʹ�������
//���� ���� �������� ����
//���� ��ġ ���� ���� ����
//���� ���� ������� ���� ���� ���� �ֱ�
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;
	
	vector<vector<int>> rocks;
	for (size_t i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		rocks.push_back({ m,v });
	}

	sort(rocks.begin(), rocks.end(), [](const auto& a,const auto& b) {
		if (a[0] != b[0]) return a[0] < b[0];
		else return a[1] > b[1];
		});
	
	vector<int> bags;
	for (size_t i = 0; i < k; i++)
	{
		int bag;
		cin >> bag;
		bags.push_back(bag);
	}
	sort(bags.begin(), bags.end());


	int j = 0;
	long long sum = 0;
	priority_queue<int> result;
	for (auto c : bags)
	{
		while (j < n && rocks[j][0] <= c)
		{
			result.push(rocks[j][1]);
			j++;
		}
		if (!result.empty())
		{
			sum += result.top();
			result.pop();
		}
	}
	cout << sum;
}