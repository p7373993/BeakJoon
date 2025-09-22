#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> adj(n + 1);
	for (size_t i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	for (auto& v : adj)
	{
		sort(v.begin(), v.end());
	}

	vector<int> dfs;
	queue<int> bfs;
	vector<int> visited(n + 1, 0);
	//dfs;
	dfs.push_back(r);
	int cnt = 1;
	
	//cout << r << " ";
	while (!dfs.empty())
	{
		int u = dfs.back(); dfs.pop_back();
		if (visited[u] != 0) continue;
		visited[u] = cnt++;
		cout << u << " ";
		for (int i = adj[u].size()-1; i>=0 ; i--)
		{
			int v = adj[u][i];
			if (visited[v] == 0)
			{
				dfs.push_back(v);
				//cout << v << " ";
			}
		}
	}
	cout << "\n";
	for (auto& v : visited)
	{
		v = 0;
	}
	bfs.push(r);
	visited[r]=1;
	while (!bfs.empty())
	{
		int u = bfs.front(); bfs.pop();
		cout << u << " ";
		for (auto& v : adj[u])
		{
			if (visited[v] == 0)
			{
				visited[v] = 1;
				bfs.push(v);
			}
		}
	}

}