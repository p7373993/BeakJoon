#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	map<int, int> m;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		vec[i] = num;
		m[num]++;
		sum += num;
	}
	sort(vec.begin(), vec.end());
	vector<int> max_vec;
	int max = 0;
	for (auto& [key, value] : m)
	{
		if (value > max)
		{
			max_vec.clear();
			max = value;
			max_vec.emplace_back(key);
		}
		else if (value == max)
		{
			max_vec.emplace_back(key);
		}
	}
	sort(max_vec.begin(), max_vec.end());
	cout << ((round(double(sum)/n)==-0) ? 0:(round(double(sum) / n)))<< "\n" << vec[(n + 1) / 2 - 1] << "\n";
	cout << ((max_vec.size() >= 2) ? max_vec[1] : max_vec[0]) << endl;
	cout << (*(vec.end()-1) - *vec.begin());
	
}