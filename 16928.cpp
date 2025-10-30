#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;

int main()
{
	//�� ��Ȳ���� 1~6ĭ �̵� �����ϰ� ������ĭ�� ������� ���µ� �󸶳� �ɷȴ��� ����α�
	//�� ���Կ� ��Ȳ�� �տ� ������ �װ� ����
	//��ٸ��� �� ĭ�� ������ �� ĭ���� �̵��ϱ�
	int n, m;
	cin >> n >> m;

	vector<int> vec(101, INT_MAX);
	unordered_map<int, int> mp;
	int x, y;
	for (size_t i = 0; i < n; i++)
	{
		cin >> x >> y;
		mp[x] = y;
	}

	for (size_t i = 0; i < m; i++)
	{
		cin >> x >> y;
		mp[x] = y;
	}

	queue<int> que;
	que.emplace(1);
	vec[1] = 0;
	while (!que.empty())
	{
		int u = que.front(); que.pop();

		for (int i = 1; i < 7; i++)
		{
			int v = u + i;
			//v�� mp�� �����Ѵٸ�
			if (v > 100) break;
			if(mp.find(v)!=mp.end()) v = mp[v];
			if (vec[v] > vec[u] + 1)
			{
				vec[v] = vec[u] + 1;
				que.emplace(v);
			}
		}
	}

	cout << vec[100];
}