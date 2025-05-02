#include <iostream>
#include <stack>
#include <queue>
using namespace std;



void ha(int n,int a,int b, queue<pair<int, int>>& s,int& count)
{
	if (n == 1)
	{

		s.push({ a, b });
		count++;
		return;
	}
	int c= 6-a-b;

	ha(n - 1, a, c, s, count);
	s.push({ a,b });
	count++;
	ha(n - 1, c, b, s, count);



}
int main()
{
	int n;
	cin >> n;
	queue<pair<int, int>> s;
	int count =0;
	ha(n, 1, 3, s, count);
	int num = s.size();
	cout << count << "\n";
	for (size_t i = 0; i < num; i++)
	{
		cout << s.front().first << " " << s.front().second << "\n";
		s.pop();
	}
}