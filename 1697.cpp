#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//길은 항상 3개?
// +1 -1 *2 이걸 모든 경우의수에 계속?
//3**n 인데 시간이 될까? 2^8정도가 10만이니깐
//3^8정도의 경의수아닐까 최대
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();

	int n, k;

	cin >> n >> k;
	vector<int> vis(100001,0);

	vis[n] = 1;
	queue<int> st;
	st.push(n);

	int dx[2] = { -1,1 };

	auto inb = [&](int x)
		{
			return x >= 0 && x <= 100000;
		};
	while (!st.empty())
	{
		int u = st.front(); st.pop();

		if (u == k) break;
		for (size_t i = 0; i < 2; i++)
		{
			int v = u + dx[i];

			if (inb(v) && vis[v] == 0)
			{
				st.push(v);
				vis[v] = vis[u]+1;
			}
			
		}
		int v = u * 2;

		if (inb(v) && vis[v] == 0)
		{
			st.push(v);
			vis[v] = vis[u] + 1;
		}
	}

	cout << vis[k] - 1;
}