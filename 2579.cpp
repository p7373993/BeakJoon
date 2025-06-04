#include <iostream>
#include <algorithm>

using namespace std;
//��ȭ�� ���� �Խ��� ����..

//f(n) = f(n-2) + an ,f(n-3) + an-1 + an	

//�߰��� ������ �ְ� ��ȭ���� ¥�θ� �ڵ����� ��ĭ�� �����

int stairs[301];
int dp[301];

int main()
{
	int n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		int a;
		cin >>a;
		stairs[i] = a;
	}
	dp[0] = stairs[0];
	if(n>1) dp[1] = stairs[0] + stairs[1];
	if(n>2) dp[2] = max(stairs[0] + stairs[2],stairs[1]+stairs[2]);
	for (size_t i = 3; i < n; i++)
	{
		dp[i] = max((dp[i- 2] + stairs[i]), (dp[i - 3] + stairs[i - 1] + stairs[i]));
	}

	cout << dp[n-1];
}