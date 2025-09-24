#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int l;
		cin >> l;
		vector<vector<int>> xy(l, vector<int>(l,0));
		int a, b;
		cin >> a >> b;
		queue< pair<int, int>> st;
		st.push({ a,b });
		xy[a][b] = 1;
		int n, m;
		cin >> n >> m;

		int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
		int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

		auto inb = [&](int x, int y)
			{
				return x >= 0 && x < l && y >= 0 && y < l;
			};
		while (!st.empty())
		{
			auto [x, y] = st.front(); st.pop();

			if (x == n && y == m)
			{
				//cout << "test xy: "<<x << y<< "\n";
				break;
			}
			for (size_t i = 0; i < 8; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];

				if (inb(nx, ny) && xy[nx][ny] == 0)
				{
					st.push({ nx,ny });
					xy[nx][ny] = xy[x][y] + 1;
				}
			}
		}
		cout << xy[n][m] - 1<<"\n";
	}
}