#include <iostream>
using namespace std;
/*
c=, c - , dz=, d- , lj, nj, s=, z =
c,s,z > =
c,d, > -
l,n > j
dz > = 이건 예외처리해주기
if문으로 노가다식으러 문제 해결? dz,z,d
map을 써서 가능? 
*/


int main()
{
	string str;
	cin >> str;
	int count = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'z')
		{
			if (str[i + 1] == '=')
			{
				count++;
				i++;
				continue;
			}
		}
		if (str[i] == 'c' || str[i] == 'd')
			if (str[i + 1] == '-')
			{
				count++;
				i++;
				continue;
			}
		if (str[i] == 'l' || str[i] == 'n')
			if (str[i + 1] == 'j')
			{
				count++;
				i++;
				continue;
			}
		if(str[i] =='d')
			if (str[i + 1] == 'z' && (str[i+2]=='='))
			{
				count++;
				i += 2;
				continue;
			}
		count++;
	}

	cout << count;
	return 0;
}