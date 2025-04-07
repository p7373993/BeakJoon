#include <iostream>
#include <vector>
using namespace std;

int gcb(int a, int b)
{
	if (b == 0) return a;
	return gcb(b, a % b);
}
int main()
{
	int n,first;
	cin >> n;
	vector<int> vec;
	cin >> first;
	for (int i = 0; i < n-1; i++)
	{
		int a;
		cin >> a;
		vec.emplace_back(a-first);
		first = a;
	}
	int result=gcb(vec[0], vec[1]);;
	for (int i = 2; i < n-1; i++)
	{
		result = gcb(result,vec[i]);
	}
	int sum = 0;
	for (auto& v : vec)
	{
		sum += (v - result) / result;
	}
	cout << sum;
}
//0 8 2 4 6
//(8-2)/2
//최대 공약수 구하고 각견에서 한번 뺴고 더하기

