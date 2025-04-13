#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> vec;
	deque<int> que;
	vec.emplace_back(0);

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		vec.emplace_back(a);
		que.push_back(i);
	}
	int index = vec[que.front()];
	cout << que.front() << " ";
	que.pop_front();
	while (!que.empty())
	{


		if (index > 0)
		{
			for (int i = 0; i < index-1; i++)
			{
				que.push_back(que.front());
				que.pop_front();
			}
			index = vec[que.front()];
			cout << que.front() << " ";
			que.pop_front();
		}
		else
		{
			index *= -1;
			for (int i = 0; i < index - 1; i++)
			{
				que.push_front(que.back());
				que.pop_back();
			}
			index = vec[que.back()];
			cout << que.back() << " ";
			que.pop_back();
		}
		
	}

}