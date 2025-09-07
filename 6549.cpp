#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//return 은 L M R 중 max?



long long bt(int first, int last, vector<long long> &vec)
{
	if (first == last)
	{
		return vec[last];
	}
	int mid = (last + first) / 2;
	long long mx = max(bt(first,mid,vec),bt(mid+1,last,vec));

	//가운데 포함값 만들건데 우서 가운데 2개값구하고 왼오 중에 
	//큰곳으로 가는데 이전 값보다 작아지면 그대로 끝
	//처음 두 막대중 짧은 길이 선택 이후 넓이 구한다
	// 좌우 중 더 긴걸 선택 다시 길이 비교후 넓이 구한다(근데 범위가 밖으로 나가면?)
	//이거를 반복하는데 넓이가 작아지면 그대로 탈출
	int i = mid; int j = mid + 1;
	long long h = min(vec[i], vec[j]);
	long long cross = h * 2;

	while (i > first || j < last)
	{
		bool canLeft = (i > first);
		bool canRight = (j < last);

		if (canRight && canLeft)
		{
			if (vec[i - 1] >= vec[j + 1])
			{
				--i;
				h = min(h, vec[i]);
			}
			else
			{
				++j;
				h = min(h, vec[j]);
			}
		}
		else if (canLeft)
		{
			--i;
			h = min(h, vec[i]);
		}
		else
		{
			++j;
			h = min(h, vec[j]);
		}

		long long w = j - i + 1;
		long long area = h * w;
		cross =max(cross, area);
	}

	return max(cross, mx);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			return 0;
		}

		vector<long long> height(n+2,0);
		for (size_t i = 1; i <= n; i++)
		{
			cin >> height[i];
		}
		cout << bt(1, n, height)<<"\n";
	}

}

// L 과 R로 재귀 분할 실시 > 왼쪽 포함 오른쪽 위 3가지 경우에서 최댓값을구한다
//