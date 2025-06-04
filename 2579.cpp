#include <iostream>
#include <algorithm>

using namespace std;
//��ȭ�� ���� �Խ��� ����..

//f(n) = f(n-2) + an ,f(n-3) + an-1 + an	

//�߰��� ������ �ְ� ��ȭ���� ¥�θ� �ڵ����� ��ĭ�� �����
int main()
{
	int n;
	cin >> n;
	int stairs[301];
	int dp[301];
	for (size_t i = 0; i < n; i++)
	{
		int a;
		cin >>a;
		stairs[i] = a;
	}
	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	for (size_t i = 2; i < n; i++)
	{
		dp[i] = max(dp[n - 2] + stairs[i], dp[n - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << dp[n - 1];
}