#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> strings(5);
	string in;
	
	for (int i = 0; i < 5; i++)
	{
		cin >> in;
		strings[i] = in;
	}
	char temp;
	for (int j = 0; j < 15; j++)
	{

		for (int i = 0; i < 5; i++)
		{
			if (j < int(strings[i].length())) {
				temp = strings[i][j];
				cout << temp;
			}
		}
	}
	return 0;
}