#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct cmp {
	bool operator()(int a, int b)
	{
		long long absa = a < 0 ? -(long long)a : (long long)a;
		long long absb = b < 0 ? -(long long)b : (long long)b;
		if (absa != absb)  return absa > absb;
		return a > b;

	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int temp;
	priority_queue<int, vector<int>, cmp> pq;


	while (n--)
	{
		cin >> temp;
		if (temp != 0)
		{
			pq.push(temp);
		}
		else if (pq.empty()) cout << "0\n";
		else
		{
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}