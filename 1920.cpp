#include <iostream>
#include <vector>
#include <algorithm>
//�Է� ���� �ϴ� ����? �� ���� �� ���� �ִ��� Ȯ��

using namespace std;

bool bt(int L, int R, vector<int>& A,int num)
{
	if (L == R)
	{
		if (A[L] != num) return false;
	}
	int mid = (R + L) / 2;
	bool ok;
	if (A[mid] == num)
	{
		ok = true;
	}
	else if (A[mid] > num)
	{
		ok = bt(L, mid, A, num);
	}
	else
	{
		ok = bt(mid + 1, R, A, num);
	}
	return ok;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> A(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	int m;
	cin >> m;
	int num;
	for (size_t i = 0;i < m; i++)
	{
		cin >> num;
		cout << bt(0, n - 1, A, num)<<"\n";
	}


}