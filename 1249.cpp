#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;


struct triple {
	int value;
	int x;
	int y;

};

struct cmp {
	bool operator()(const triple& a, const triple& b) const {
		return a.value > b.value;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		int n;
		cin >> n;
		vector<vector<int>> val(n, vector<int>(n,INT_MAX));
		vector<string> mp(n);
		for (int i = 0; i < n; i++)
		{
			cin >> mp[i];
		}
		//우선순위 큐를 하는 좌표+ 코스트

		priority_queue<triple,vector<triple>,cmp> pq;
		//priority_queue<triple> pq;

		pq.push({ 0,0,0 });
		val[0][0] = 0;
		int dy[4] = { 1, -1, 0, 0 };
		int dx[4] = { 0, 0,1, -1 };

		while (!pq.empty())
		{
			auto [v, x, y] = pq.top(); pq.pop();

			if (v > val[y][x]) continue;

			if (x == n - 1 && y == n - 1)
			{
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + x; int ny = dy[i] + y;

				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					int dv = mp[ny][nx]-'0';
					int nv = v + dv;
					if (nv < val[ny][nx]) {
						val[ny][nx] = nv;
						pq.push({ nv, nx, ny });
					}
				}
			}
		}

		cout << "#"<<test <<" "<<val[n - 1][n - 1]<<"\n";
	}
}