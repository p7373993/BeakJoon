#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//���� �׻� 3��?
// +1 -1 *2 �̰� ��� ����Ǽ��� ���?
//3**n �ε� �ð��� �ɱ�? 2^8������ 10���̴ϱ�
//3^8������ ���Ǽ��ƴұ� �ִ�
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