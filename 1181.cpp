#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//���̰� ª�� ����
//������
//���� ���ڴ� ����

//sort�ϰ� �� �ձ��ڶ� ������ continue?
bool comlen(string a, string b)
{
	if (a.length() > b.length()) return false;
	else if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] > b[i])
			{
				return false;
			}
		}
		return true;
	}
	else return true;
	
}

int main()
{
	int n;
	string str;
	cin >> n;
	vector<string> vec;
	bool out = false;
	for (int i = 0; i < n; i++)
	{
		out = false;
		cin >> str;
		for (auto& v : vec)
		{
			if (v == str)
			{
				out = true;
				break;
			}
		}
		if (out) continue;
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end(), comlen);

	for (auto& v : vec)
	{
		cout << v << endl;
	}
}