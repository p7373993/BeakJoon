#include <iostream>
#include <stack>
#include <queue>
using namespace std;
	//스택일 경우는 필요 없다?//큐의 값들이 순서대로 나온다........

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> vec2(n);
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec[i] = a;
	}

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >>a;
		vec2[i] = a;
	}

	for (int i = n-1; i >=0 ; i--)
	{
		if (vec[i] == 0)
		{
			q.push(vec2[i]);
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		q.push(a);
	}

	for (int i = 0; i < m; i++)
	{
		cout << q.front() << " ";
		q.pop();
	}
}

