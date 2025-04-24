#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct wordInfo {
	string word;
	int count;
	int length;

	wordInfo(string w, int c, int l) : word(w), count(c), length(l) {}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<wordInfo> vec;
	unordered_map<string, int> map;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		if (a.size() < m) continue;
		map[a]++;
	}

	for (auto& [word, count] : map)
	{
		vec.emplace_back(word, count, int(word.size()));
	}

	sort(vec.begin(), vec.end(),[&](const wordInfo& a, const wordInfo& b)
		{
			if (a.count != b.count) return a.count > b.count;
			if (a.length != b.length) return a.length > b.length;
			return a.word < b.word;
		}
	);

	for (auto& s : vec)
	{
		cout << s.word << "\n";
	}
}