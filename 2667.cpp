#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//������ 1 Ž��
//ã�� 1 �������� bfs ���� 
// 1�� ��� ã��? �� ������ �и��Ǿ����� ó���� �𸣴ϱ� ���� �밡�ٷ� ã�ƾ��� ��
//�ֺ� ������ ��ǥ���� ���� ���ڸ����� �ĺ�?
//ads[1,1] = 1,2/2,1(L,R,U,D) < �̰��� �׋� �׋� ã�Ƽ� �ִ°� ������ �ƴϸ� �̸� ����� << �׶� �׋� �ֱ�
//�����̵� �� 1���� 0���� ���� 
int n;

//���ϰ����� ����Ʈ ��
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
		//���⼭ UD RL ���� ���ϱ�
			//���̾ƴѰ� &&1�ΰ�
		if (i > 1 && map[i - 1][j] == '1') st.push({ i - 1,j });//��
		if (i < n && map[i + 1][j] == '1') st.push({ i + 1,j });//�Ʒ�
		if (j > 1 && map[i][j - 1] == '1') st.push({ i,j - 1 });//��
		if (j < n && map[i][j + 1] == '1') st.push({ i,j + 1 });//��
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

	//1ã�� for������ ��� ���� ����
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
