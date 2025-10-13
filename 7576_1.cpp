#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//bfs�� ������ ���ڰ����� ������ +1 �ؼ� ��¥�� Ȯ���ϱ� 
//��� �丶�䰡 �;����� Ȯ���ϰ� ������ �� ��¥�� ����ū ���� ã�Ƴ��� �������� -1 ���
// �̷��� ���ʹ� ���� {-1 1 0 0} {0 0 -1 1} �ؼ� �����¿츦 ���Ѵ�
// �������� ���� dp�����ҋ� ���ÿ� �־� ���� ����
// while������ �ҰŸ� �� ���ð��� ��¥�� ���� �ֹ�����
// ���� �Լ��� ����� �μ��� ��¥ ���ֱ�
//dp(����)
//������ bfs�� ���ϰ� �ѹ��� ��� ���� �о�� �ߴµ�
//�̸� ���� ����� bfs�ϸ鼭 ������ �������� ? ��ó�� �ð����⵵�� ������?

//gpt �ǵ�� ���� ��¥�� node �������� vec�� ��¥ ����ֱ�
//vec���鋚 0�� ������ ���� �ϳ��� ������� �̰ɷ� -1 ���� �Ǵ��ϱ�
struct node {
	int i, j;
};
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> m >> n;

	vector<vector<int>> vec(n, vector<int>(m));
	queue<node> que;
	int tmp;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			vec[i][j] = tmp;
			if (tmp == 1) que.emplace(node{ i,j});
			if (tmp == 0) total++;
		}
	}
	int mx = 0;
	int dr[4] = { -1, 1 , 0 ,0 };
	int dc[4] = { 0 ,0,-1 ,1 };

	while (!que.empty())
	{
		auto [i, j] = que.front(); que.pop();

		if (vec[i][j] > mx) mx = vec[i][j];
		//if (vec[i][j] == -1) cout << "test";
		for (int k = 0; k < 4; k++)
		{
			int nr = i + dr[k], nc = j + dc[k];

			//�ڽ� ���� + 0�ϋ�
			if (nr < n && nr >= 0 && nc < m && nc >= 0 && (vec[nr][nc] == 0))
			{
				vec[nr][nc] = vec[i][j]+1;
				total--;
				que.emplace(node{ nr, nc});
			}
		}
	}

	if (total == 0)cout << mx - 1;
	else cout << -1;
	
	return 0;
}