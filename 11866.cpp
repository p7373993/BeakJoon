#include <iostream>
#include  <queue>
#include <vector>
using namespace std;

int main()
{
	queue<int> q;
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	int k;
	cin >> k;
	while (!q.empty())
	{
		for (int i = 1; i < k; i++)
		{
			q.push(q.front());
			q.pop();
		}
		vec.emplace_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < vec.size(); i++)
	{
		if (i == vec.size() - 1)
		{
			cout << vec[i] << ">";
			break;
		}
		cout << vec[i] << ", ";
	}
}