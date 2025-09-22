#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int order = 1;
void dfs(vector<int>& V, vector < priority_queue<int, vector<int>, greater<int>>>& E, int root)
{
	V[root] = order++;

		//시작점이 root인 간선 모두 찾아서 다 dfs 돌리기?
		//간선 모음을 map으로? {1:[2,3,4] 이런식으로?
	while (!E[root].empty())
	{
		int temp = E[root].top();
		E[root].pop();
		if (V[temp] == 0) dfs(V, E, temp);
	}
	
}

int main()
{
	int n, m, r;
	cin >> n >> m >> r;
	vector < priority_queue<int,vector<int>,greater<int>>> E(n+1);
	vector<int> V(n+1,0);
	for (size_t i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].push(v);
		E[v].push(u);
	}
	dfs(V, E, r);

	V.erase(V.begin());
	for (auto v : V)
	{
		cout << v << "\n";
	}
}