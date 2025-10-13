#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//bfs를 돌리되 인자값으로 이전날 +1 해서 날짜를 확인하기 
//모든 토마토가 익었는지 확인하고 맞으면 저 날짜가 제일큰 값을 찾아내며 안익으면 -1 출력
// 이러한 벡터는 보통 {-1 1 0 0} {0 0 -1 1} 해서 상하좌우를 비교한다
// 시작점은 따로 dp시작할떄 스택에 넣어 놓고 시작
// while문으로 할거면 각 스택값에 날짜를 같이 넣버리기
// 따로 함수를 만들면 인수에 날짜 값넣기
//dp(벡터)
//원래는 bfs를 다하고 한번더 모든 판을 읽어야 했는데
//미리 판을 만들고 bfs하면서 익은걸 빼버리면 ? 어처피 시간복잡도는 같을듯?

//gpt 피드백 따로 날짜를 node 넣지말고 vec에 날짜 집어넣기
//vec만들떄 0의 갯수를 세고 하나씩 지운다음 이걸로 -1 인지 판단하기
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

			//박스 안쪽 + 0일떄
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