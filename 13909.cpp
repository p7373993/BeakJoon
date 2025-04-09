#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num = 0;
	for (int i = 1; i*i <= n; i++)
	{
		num++;
	}

	cout << num;
}
//n 이 주어지ㅏ면 1부터 n까지의 약 배수?
//소수면 일단 열리고 끝이다> 결국 닫힘
//그 외의 수는 약수의 갯수로 따진다?>>제곱수가 아니면 약수는 짝수개다 닫힘

