#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//그리디로 한번에 할 수도 있고
//좀 머리써서 규칙을 찾아서 할수도 있을ㄷ스
//10개 테스트 10초면 걍 그1리디 해도 될듯?

//규칙을 찾는다면 n 번쨰 건물에서 n-1,n-2,N+1,n+2 의 최댓값과 n의 높이를 뺴면 된다
int main()
{
	int col;
	cin >> col;

	//앞뒤로 2칸 따로 예외처리하기 귀찮으니 여기서 추가하자
	vector<int> height(col);
	long long value = 0;

	for (size_t i = 0; i < col; i++)
	{
		cin >> height[i];
	}
	
	for (size_t i = 2; i < col-2; i++)
	{
		int tmp1, tmp2;
		tmp1 = max(height[i - 2], height[i - 1]);
		tmp2 = max(height[i + 2], height[i + 1]);
		int mx = max(tmp1, tmp2);

		if (mx >= height[i]) continue;
		value += height[i] - mx;
	}

	cout << value;
}