#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<bool>> cabbage(n, vector<bool>(m,false));
		for (size_t i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			cabbage[x][y] = true;
		}
		int dx[4] = { -1,1,0,0 };
		int dy[4] = { 0,0,-1,1 };

		int cnt = 0;
		auto inb = [&](int x, int y) {
			return x>=0&&x<=n-1&&y>=0&&y<=m-1;
			};
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				if (cabbage[i][j])
				{
					queue<pair<int, int>> st;
					st.push({ i,j });
					cabbage[i][j] = false;
					while (!st.empty())
					{
						auto [x, y] = st.front(); st.pop();
					//cout << "Test xy" << x << " :" << y << "\n";
						for (size_t l = 0; l < 4; l++)
						{
							int nx = x + dx[l], ny = y + dy[l];
							if (inb(nx, ny) && cabbage[nx][ny])
							{
							//cout << "NX : NY" << nx << " : " << ny << "\n";
								st.push({ nx,ny });
								cabbage[nx][ny] = false;
							}
						}
					}
					cnt++;

				}
			}
		}

		cout << cnt<<"\n";
	}
}