#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	long long total;
	long long temp;
	int digit, length;
	vector<int> nums;
	cin >> total >> digit;
	temp = total;
	
	if (total == 0) nums.push_back(0);
	for (int i = 0; true; i++)
	{
		if (total < pow(digit, i))
		{
			length = i - 1; 
			break;
		}
	}
	for (int i = length; i >=0 ; i--)
	{
		for (int j = digit - 1; j >= 0; j--)
		{
			if (temp >= pow(digit, i) * j) {
				temp -= pow(digit, i) * j;
				nums.push_back(j);
				break;
			}
		}
	}
	for (auto& a : nums)
	{
		if (a >=10) cout << char(a + 55);
		else cout << a;
	}
}