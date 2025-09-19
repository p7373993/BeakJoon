#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	while(n--)
	{
		
		int m;
		cin >> m;
		priority_queue<int> left = {};
		priority_queue<int, vector<int>, greater<int>> right = {};

		cout << (m + 1) / 2<<"\n";
		for (size_t i = 1; i <= m; i++)
		{
			int x;
			cin >> x;
			if (left.size()==0)
			{
				left.push(x);
				//cout << "1\n";
			}
			else
			{
				//cout << "2\n";
				if (left.top() <= x)
				{
					right.push(x);
				}
				else left.push(x);

				if (left.size() < right.size())
				{
					left.push(right.top());
					right.pop();
				}
				else if (left.size() > right.size()+1)
				{
					right.push(left.top());
					left.pop();
				}
			}
			if(i%2 == 1)
			{
				cout << left.top()<<"\n";
			}
		}
	}
}