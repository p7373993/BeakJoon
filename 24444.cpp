#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;

	vector<vector<int>> adj(n + 1);
	for (size_t i = 1; i < m+1; i++)
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

	vector<int> visited(n + 1, 0);
	int cnt = 1;
	queue<int> st;

	st.push(r);
	visited[r] = cnt++;
	while (!st.empty())
	{
		int u = st.front(); st.pop();
		for (auto& v : adj[u])
		{
			if (visited[v] == 0)
			{
				visited[v] = cnt++;
				st.push(v);
			}
		}
	}

	
	visited.erase(visited.begin());
	for (auto& v : visited)
	{
		cout << v << "\n";
	}
}