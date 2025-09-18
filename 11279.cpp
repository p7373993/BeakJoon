#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int> pq;

	for (size_t i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp != 0)
		{
			pq.push(temp);
		}
		else if(pq.size() ==0)
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