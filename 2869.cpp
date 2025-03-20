#include <iostream>

using namespace std;

int main()
{
	//하루에 a-b 만큼 움직인다
	//a-b 가 v를 넘는다면 그 이후엔?
	//v-a 에 
	//(V-A) % (A-B) == 0 일떄를 예외처리해라
	long long a, b, v;
	int total = 0;
	cin >> a >> b >> v;
	if ((v - a) % (a - b) == 0)
	{
		total = (v - a) / (a - b) +1 ;
	}
	else total = (v - a) / (a - b)+2;

	cout << total;
}