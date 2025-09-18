#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int,vector<int>,greater<int>> pq;

	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num != 0)
		{
			pq.push(num);
		}
		else if (pq.empty())
		{
			cout << "0\n";
		}
		else
		{
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}