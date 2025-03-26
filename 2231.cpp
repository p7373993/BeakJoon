#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,result=0;
	int temp = 0;
	int temp2=0;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		temp2 = i;
		str = to_string(i);
		for (auto& s : str)
		{
			temp2 += int(s)-int('0');
		}
		if (temp2 == n)
		{
			result = i;
			break;
		}
	}
	cout << result;
}