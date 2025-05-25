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
	back(3,4, 0);

	cout << total;
}