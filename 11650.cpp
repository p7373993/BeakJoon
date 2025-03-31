#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//x�� ���� �ϴ¼����� ���� ��� y�� �����ϴ� ������ ����
// y���� �� x ���� >> �ð� �ʰ��� ���� (���� ������ ����ؼ� �ð� �ʰ�)
// vec�� sort �Լ��� ����Ϥ��� >> 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,x,y;

	cin >> n;
	vector<vector<int>> vec(200001);
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		vec[x + 100000].push_back(y);
	}

	for (int i = 0; i <= 200000; i++)
	{
		if (vec[i].size() > 0)
		{
			sort(vec[i].begin(), vec[i].end());
			for (auto& v : vec[i])
			{
				cout << i - 100000 << ' ' << v <<'\n';
			}
		}
	}
}

