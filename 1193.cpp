#include <iostream>

using namespace std;

int main()
{
//대각선 합이 2> 3 > 4 >5
	//홀짝 구분해서 어디서 시작할지 결정
	//짝일떄 왼쪽부터

	//피보나치 수열을 통해 줄 구하기
	//줄에서 어디 위치인지 특정

	int n,ex;
	int temp = 0;
	int line;
	cin >> n;
	for (int i = 0; true; i++)
	{
		if (n <= temp) {
			line = i;
			ex = temp - i+1;
			break;
		}
		temp += i;
	}

	int a,b;
	a = temp - ex;
	b = n - ex;
	//temp = 현재 라인에 최고 수
	//ex =이전라인에 최고수
	//a = 현재 라인에 숫가 개수
	//n- ex 이후 for문

	if(line%2 ==0) cout << line - b << "/" << b;
	else cout << b << "/" << line - b;
	//cout <<temp<<endl<<ex<<endl<<line;
}