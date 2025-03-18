#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int max=0;
	int input;
	int r=0, c=0;
	vector<int> col(9);
	vector<vector<int>> row(9,vector<int>(9));
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> input;
			row[i].push_back(input);
			if (max < input) {
				r = i;
				c = j;
				max = input;
			}
		}
	}

	cout << max << endl << r+1 <<' '<< c+1;
}