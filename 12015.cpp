#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bound(vector<int>& num, int temp)
{
	int lo = 0;
	int hi = num.size()-1;
	int ans = 0;
	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (num[mid] >= temp)
		{
			hi = mid - 1;
			ans = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	num[ans] = temp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> num;
	num.reserve(n);
	int temp;
	cin >> temp;
	num.push_back(temp);
	for (size_t i = 1; i < n; i++)
	{
		cin >> temp;

		if (*(num.end()-1)< temp)
		{
			num.push_back(temp);
		}
		else
		{
			//bound(num, temp);
			auto it = lower_bound(num.begin(), num.end(), temp);
			*it = temp;
		}
	}

	cout << num.size();
	//���� Ž�� �����ϱ� �̰͵� lo hi?
	//��Ʈ > �� ���Һ� �� ���� �ǵ��� ������ ũ�� �ǵڿ� �ְ� 

}