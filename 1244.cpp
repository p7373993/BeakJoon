#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int num;
		string str;
		cin >> str >> num;
		int sz = str.size();
		unordered_set<string> current;
		current.insert(str);
		while (num--)
		{
			unordered_set<string> tmp;
			for (auto str : current)
			{
				for (int i = 0; i < sz; i++)
				{
					for (int j = i+1; j < sz; j++)
					{

						swap(str[i], str[j]);
						tmp.insert(str);
						swap(str[i], str[j]);
					}
				}

			}
			current.swap(tmp);
		}

		string best = *current.begin();
		for (const auto& tmp : current)
		{
			if (best < tmp) best = tmp;
		}
		cout << "#" << test+1 << " " << best << '\n';
	}

	return 0;
}
