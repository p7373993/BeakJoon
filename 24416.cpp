#include <iostream>
#include <vector>
using namespace std;

int back = 0;
int dynamic = 0;
vector<int> vec;
int fib(int n)
{
	if (n == 1 || n == 2)
	{
		back++;
		return 1;
	}
	else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n)
{
	vec.emplace_back(1), vec.emplace_back(1);
	for (size_t i = 2; i < n; i++)
	{
		dynamic++;
		vec.emplace_back(vec[i - 1] + vec[i - 2]);
	}
	return  vec[n-1];
}
int main()
{
	int n;
	cin >> n;
	fib(n);
	fibonacci(n);

	cout << back << " " << dynamic;
}