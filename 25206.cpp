#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
/*뒤에서 2글자 or \0 나올때 까지는 점수
그뒤 숫자는 점수
라인을 입력받고 학점x평점 / 총학점 */


float result(const float& time, const string& scorestr)
{
	float score;
	if (scorestr == "A+") score = 4.5;
	else if (scorestr == "A0") score = 4.0;
	else if (scorestr == "B+") score = 3.5;
	else if (scorestr == "B0") score = 3.0;
	else if (scorestr == "C+") score = 2.5;
	else if (scorestr == "C0") score = 2.0;
	else if (scorestr == "D+") score = 1.5;
	else if (scorestr == "D0") score = 1.0;
	else score = 0;

	return (time * score);
}
int main()
{
	string a,b,c;
	float total=0;
	float times = 0;
	while (cin >> a >>b >>c )
	{
		if (a.empty() || b.empty() || c.empty()) break;
		if (c == "P") continue;
		total += result(stof(b),c);
		times += stof(b);
	}
	float result = total / times;
	cout << result;
	return 0;
}