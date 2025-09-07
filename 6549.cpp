#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//return �� L M R �� max?



long long bt(int first, int last, vector<long long> &vec)
{
	if (first == last)
	{
		return vec[last];
	}
	int mid = (last + first) / 2;
	long long mx = max(bt(first,mid,vec),bt(mid+1,last,vec));

	//��� ���԰� ����ǵ� �켭 ��� 2�������ϰ� �޿� �߿� 
	//ū������ ���µ� ���� ������ �۾����� �״�� ��
	//ó�� �� ������ ª�� ���� ���� ���� ���� ���Ѵ�
	// �¿� �� �� ��� ���� �ٽ� ���� ���� ���� ���Ѵ�(�ٵ� ������ ������ ������?)
	//�̰Ÿ� �ݺ��ϴµ� ���̰� �۾����� �״�� Ż��
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

// L �� R�� ��� ���� �ǽ� > ���� ���� ������ �� 3���� ��쿡�� �ִ������Ѵ�
//