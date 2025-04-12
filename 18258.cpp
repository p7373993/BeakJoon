#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> vec(n);
	int front = 0;
	int back = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int a; 
			cin >> a;
			vec[back] = a;
			++back;
		}
		else if(str == "front")
		{
			if (front != back)
			{
				cout << vec[front]<<"\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (str == "back")
		{
			if (front != back)
			{
				cout << vec[back-1] << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (str == "pop")
		{
			if (front != back)
			{
				cout << vec[front] << "\n";
				++front;
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (str == "size")
		{
			cout << back - front<<"\n";
		}
		else if (str == "empty")
		{
			if (front == back) cout << "1\n";
			else cout << "0\n";
		}
	}
}