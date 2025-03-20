#include <iostream>
#include <vector>
using namespace std;

int main() {	
	long n,num=0;
	long total=0;
	cin >> n;
	vector<long> vec;
	for (int i = 1; i <=500000; i++)
	{
		vec.push_back(num);
		num += i;
	}
	for (int i = 0; i < n-1; i++)
	{
		total += vec[i];
	}
	cout << total << endl << 3;
}