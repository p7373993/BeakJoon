#include <iostream>
#include <cmath>
using namespace std;

/*����^(�ڸ���-1)*���ڸ��� ���� */
int main() {
	string number;
	int digit;
	long long result = 0, temp;
	cin >> number >> digit;
	//length -1 -i
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] >= 'A') temp = number[i] - 'A' + 10;
		else temp = int(number[i])-int('0');
		result += pow(digit, number.length() - 1 - i) * temp;
	}
	cout << result;
}