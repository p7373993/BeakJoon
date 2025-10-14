#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//0�� ī���� �ؼ� �������� ������ Ȯ�� 
//�� ���� �ð��밡 �Ǽ� ������ �ð��� Ȯ���ϱ�

using namespace std;

struct node {
	int m, n, h;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n,h;

	cin >> m >> n >> h;
	vector<vector<vector<int>>> vec(h,vector<vector<int>>(n,vector<int>(m)));
	int tmp;
	int cnt = 0;
	queue<node> que;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> tmp;
				if (tmp == 0) ++cnt;
				if (tmp == 1) que.emplace(node{ k,j,i });

				vec[i][j][k]=tmp;

			}
		}
	}

	int dh[6] = { -1,1,0,0,0,0 };
	int dr[6] = { 0,0,-1,1,0,0 };
	int dc[6] = { 0,0,0,0,-1,1 };

	int mx = 0;

	while (!que.empty())
	{
		auto [col, row, hei] = que.front(); que.pop();

		if (mx < vec[hei][row][col]) mx = vec[hei][row][col];
		for (size_t i = 0; i < 6; i++)
		{
			int nh = hei + dh[i], nr = row + dr[i], nc = col + dc[i];

			if (nh < h && nh >= 0 && nr < n && nr >= 0 && nc < m && nc >= 0 && vec[nh][nr][nc] == 0)//������ + 0�϶�
			{
				--cnt;
				vec[nh][nr][nc] = vec[hei][row][col] + 1;
				que.emplace(node{ nc,nr,nh });
			}
		}
	}

	if (cnt != 0) cout << "-1";
	else cout << mx-1;
}