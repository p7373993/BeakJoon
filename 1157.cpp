#include <iostream>
#include <vector>
using namespace std;

int main() {

	string str;
	int max=0, second=0,temp=0;
	char c;
	vector<char> ex;
	cin >> str;
	bool dup;
	for (auto& c : str)
	{
		c = tolower(c);

	}
	for (auto i = str.begin(); i != str.end(); ++i)
	{
		dup = false;
		for (auto a : ex) 
		{ 
			if (*i == a) dup = true; continue;
		}
		if (dup == false)
		{
			temp = 0;
			for (auto j = i; j != str.end(); ++j)
			{
				if (*i == *j) ++temp;
			}
			if (temp >= max) {
				second = max;
				max = temp;
				c = *i;
			}


			ex.push_back(*i);
		}
		
	}
	if (max == second) { cout << "?"; }
	else cout << char(toupper(c));

	return 0;
}