#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


/*문자열 받아서 집합에 넣고 집합에 있는 글자를 참고하면 false
aavv > T aavva > F*/
int main()
{
	int in;
	int out = 0;
	cin >> in;
	vector<string> vStr;
	string temp;
	for (int i = 0; i < in; i++)
	{
		cin >> temp;
		vStr.push_back(temp);
	}

	for (int i = 0; i < in; i++)
	{
		unordered_set<char> exist;
		string a = vStr[i];
		bool bdobule = true;
		bool nextsame = false;
		for (int j = 0 ; j < a.length();++j)
		{
			if (nextsame)
			{
				nextsame = (a[j] == a[j + 1]);
				continue;
			}
			if (exist.find(a[j])!= exist.end())//집합에 문자가 존재할떄
			{
				bdobule = false;
				break;
			}
			exist.insert(a[j]);
			nextsame = (a[j] == a[j + 1]);
		}
		exist.clear();

		if (bdobule) out++;
	}

	cout << out;
}


