#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> adj(n + 1);

	for (size_t i = 0; i < k; i++)
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

	vector<int> visited(n + 1);

	queue<int> st;
	st.push(1);
	visited[1] = 1;
	int cnt = 0;
	while (!st.empty())
	{
		int u = st.front(); st.pop();
		for (auto v : adj[u])
		{
			if (visited[v] == 0)
			{
				visited[v] = 1;
				st.push(v);
				//cout << "test : " << v << "\n";
				cnt++;
			}
		}
		
	}

	cout << cnt;

}