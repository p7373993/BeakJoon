#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	set<string> strs;
	for (int i = 1; i <= str.size(); i++)
	{
		for (int j = 0; j <= str.size()-i; j++)
		{
			strs.insert(string(str.begin()+j ,str.begin()+j+i));
		}
	}

	cout<<strs.size();
}