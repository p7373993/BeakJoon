#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//지도내 1 탐색
//찾은 1 기준으루 bfs 실행 
// 1은 어떻게 찾지? 각 단지가 분리되었는지 처음엔 모르니깐 그저 노가다로 찾아야할 듯
//주변 간선은 좌표값을 통해 그자리에서 식별?
//ads[1,1] = 1,2/2,1(L,R,U,D) < 이값을 그떄 그떄 찾아서 넣는게 빠를까 아니면 미리 만들까 << 그때 그떄 넣기
//간선이동 후 1값을 0으로 변경 
int n;

//리턴값으로 아파트 수
int bfs(vector<string>& map, pair<int, int> root)
{
	queue<pair<int, int>> st;
	st.push(root);
	int cnt = 0;

	while (!st.empty())
	{
		pair<int, int> u = st.front(); st.pop();
		int i = u.first;
		int j = u.second;
		if (map[i][j] == '0') continue;
		map[i][j] = '0';
		cnt++;
		//여기서 UD RL 각각 구하기
			//벽이아닌가 &&1인가
		if (i > 1 && map[i - 1][j] == '1') st.push({ i - 1,j });//위
		if (i < n && map[i + 1][j] == '1') st.push({ i + 1,j });//아래
		if (j > 1 && map[i][j - 1] == '1') st.push({ i,j - 1 });//왼
		if (j < n && map[i][j + 1] == '1') st.push({ i,j + 1 });//오
	}

	return cnt;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<string> map(n + 1);
	for (size_t i = 1; i <= n; i++)
	{

		string temp;
		cin >> temp;
		temp = "0" + temp;
		map[i] = temp;
	}

	//1찾기 for문으로 모든 숫자 대조
	int num = 0;
	vector<int> cnts;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == '1') {
				cnts.push_back(bfs(map,{i,j}));
				num++;
			}
		}
	}

	cout << num << "\n";
	sort(cnts.begin(), cnts.end());
	for (auto v : cnts)
	{
		cout << v << "\n";
	}
}
