#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//nm ũ�� 
//00 -> n-1,m-1
//�� ��ǥ���� ������ ����� Ʈ������ ����?
// 00 -> 0 10 > 1 
// 11 > 2 21 >2 �̷������� �׷��� nm�ϋ� ���� �� �װ�
//���� ����ϴ°͵� �ϰ� ������ �𸣰ٴ�.
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<string> xy(n);
	vector<vector<int>> cnts(n, vector<int>(m));
	for (size_t i = 0; i < n; i++)
	{
		cin >> xy[i];
	}

	auto inb = [&](int x, int y)
		{
			return x >= 0 && x < n && y >= 0 && y < m;
		};


	queue<pair<int, int>> st;
	st.push({ 0,0 });
	xy[0][0] = '0';
	cnts[0][0] = 1;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };


	while (!st.empty())
	{
		auto [x, y] = st.front(); st.pop();

		if (x == (n - 1) && y == (m - 1)) break;
		for (size_t i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (inb(nx, ny) && xy[nx][ny] == '1')
			{
				st.push({ nx,ny });
				xy[nx][ny] = '0';
				cnts[nx][ny] = cnts[x][y] + 1;
			}
		}	
	}

	cout << cnts[n - 1][m - 1];
}