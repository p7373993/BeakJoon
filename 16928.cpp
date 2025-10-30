#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;

int main()
{
	//각 상황마다 1~6칸 이동 가능하고 도착한칸에 여기까지 오는데 얼마나 걸렸는지 적어두기
	//더 적게온 상황이 앞에 있으면 그걸 적기
	//사다리나 뱀 칸은 무조건 그 칸으로 이동하기
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
			//v가 mp에 존재한다면
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