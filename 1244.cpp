#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//328088 // 제일 큰게 제일 앞자리로
//제일 큰수가 여러개면 그 갯수만큼 앞자리숫자를 각각 비교해서 제일 큰거수슬 동일한 수의 가장 큰 자릿수와 교체
//
// 제일큰수가 제일 앞에있으면 그다음 숫자 찾기
//32088 >> 82038 >>88032
//38288 >> 88238 >> 88823
// 423>> 324 이런경운? 그냥 무조건 앞자리부터 다바꾸기
// 정리하면 9부터 1까지 값을 앞자리부터 탐색 있으면 그걸 I(1)번쨰 자리와 교체후 I+1
// 탐색하는거솓 I+1부터 탐색하기
// 159 >> 9가 3번째 있는거 확인 1과 교체
// 951

//왜 I+1부터 탐색하냐 첫번째 자리가 더크든 작든무조건 걔랑 바꿔야한다

//23888 그럼 이게 문제인데
//83288 >>88238
//28388 >> 88328 이경우처럼 해야함 즉 제일 큰값이 여러개일떈 앞의 숫자를 고려해야한다

//제일큰숫자가 하나일떈 무조건 제일 큰 자릿수와 변경
// 여러개일때 + 교환횟수 여러번 //아니 너무 복잡한데?

//걍 6자리 최대 10회면 걍 그리디가 맞다
int sz;
int mx = 0;
void bp(string str, int num)

{
	if (num == 0)
	{
		mx = max(mx, stoi(str));
		return;
	}
	for (int i = 0; i < sz; i++)
	{
		for (int j = i+1; j < sz; j++)
		{
			string backUp = str;
			char tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			bp(str, num - 1);
			str = backUp;
			
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string str;
		int num;
		cin >> str>>num;

		sz = str.size();
		
		bp(str, num);
		cout <<"#"<<i+1<<" "<< mx << "\n";
		mx = 0;
	}
	return 0;
}