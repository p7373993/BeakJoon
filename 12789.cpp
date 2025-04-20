#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> now(n);
	int index = 0;
	int now_it = 0;
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		now[i] = a;
	}
	for (int i = 0; i < 2*n; i++)
	{
		
		if (now_it < n && now[now_it] == num)
		{
			num++;
			now_it++;
		}
		else if (index > 0 && vec[index - 1] == num)
		{
			--index;
			++num;
		}
		else if(now_it<n)
		{
			vec[index] = now[now_it];
			++now_it;
			++index;
		}

		if (now_it == n&&index==0) break;
	}
	if (index == 0)cout << "Nice";
	else cout << "Sad";

	//5 2 3 1 4
}