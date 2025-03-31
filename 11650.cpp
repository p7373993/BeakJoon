#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//x가 증가 하는순으로 같을 경우 y가 증가하는 순으로 정렬
// y정렬 후 x 정렬 >> 시간 초과로 실패 (버블 정렬을 사용해서 시간 초과)
// vec에 sort 함수를 사용하ㅁ자 >> 

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

