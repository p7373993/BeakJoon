#include <iostream>

using namespace std;

int total = 0;
void back(int idx,int n,int sum)
{
	if (sum > n) return;
	if (sum == n)
	{
		total++;
		return;
	}
	for (size_t i = idx; i > 0; i--)
	{
		back(idx,n, sum + i);
	}
}
int main()
{
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		total = 0;
		back(3, num, 0);
		cout << total<<endl;
	}


}