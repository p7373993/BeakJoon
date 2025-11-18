	#include <iostream>
	#include <vector>
	#include <string>
	#include <sstream>
	#include <unordered_map>
	using namespace std;

	int main()
	{
		int t;
		cin >> t;
		unordered_map<string, int> mp = {
			{"0001101" , 0},
			{"0011001",1},
			{"0010011",2},
			{"0111101",3},
			{"0100011",4},
			{"0110001",5},
			{"0101111",6},
			{"0111011",7},
			{"0110111",8},
			{"0001011",9},
		};
		for (int test = 1; test <= t; test++)
		{
			int n, m;
			cin >> n >> m;
			vector<string> vec(n);
			for (int i = 0; i < n; i++)
			{
				cin >> vec[i];
			}
			int x, y;
			for (int i = n-1; i>= 0; i--)
			{
				bool out = false;
				for (int j = m - 1; j >= 0; j--)
				{
					if (vec[i][j] == '1')
					{
						out = true;
						y = i;
						x = j;
						break;
					}
				}
				if (out) break;
			}
			string str = vec[y].substr(x - 55, 56);

			int digits[8];
			for (size_t i = 0; i < 8; i++)
			{
				digits[i] = mp[str.substr(i * 7, 7)];
			}
			int sum = 0;
			int result = 0;

			for (int i = 0; i < 8; i++)
			{
				if (i % 2 == 0) {
					sum += digits[i] * 3;
				}
				else sum += digits[i];
				result += digits[i];
			}

			int answer = (sum % 10 == 0) ? result : 0;

			cout << "#" << test << " " << answer << "\n";
		}
	}