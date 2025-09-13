#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;
	cin >> n >> c;
	vector<long long> num(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	long long lo = 1;
	long long hi = num[n - 1];
	long long ans;

	//for (auto v : num)
	//{
	//	cout << v <<" ";
	//}
	//cout << "\n";
	//cout << lo << hi;
	while (lo <= hi)
	{
		long long d = lo + (hi - lo) / 2;
		int current=0,next = 1;
		int count = 1;
		int boolOk=true;
		//cout << "d = " << d << "\n";

		while (count < c)
		{
			if (num[current] + d <= num[next] && (next<n))
			{

				//cout << "True if : next & count " << next << " & " << count << "\n";

				
				++count;
				current = next;
				++next;
			}
			else
			{
				//cout << "else : next & count " << next << " & " << count << "\n";
				++next;
				if (next >= n)
				{
					//cout << "false \n";
					boolOk = false;
					break;
				}
			}
		}
		if (boolOk)
		{
			lo = d + 1;
			ans = d;
			//cout << "Test case (ans,lo,hi)   " << ans <<":" << lo<<":" << hi << '\n';
		}
		else
		{
			hi = d - 1;
		}

	}

	cout << ans;
}
//C의 취치를 잡고 그걸 기반으로 거리 d를 구할려고 해봤는데 답이없음
// gpt한테 힌트달라하니 최대 거리 d를 먼저 설정하고 d가 가능한지 아닌지에 따라 이분탐색 진행


//어떻게 ? lo + hi /2 로 d 설정? 이 부분은 이전과 동일할듯
//제일 구현이 복잡할거 같은게 좌표값에 따른 가능여부 조사일듯 << 어떻게 하지
// num[i] + d < num[i+a] 하고 num[i+a] + d <num[j] 이거를 c번 반복이 되는가를 체크 하기
//그러면 고민인게 처음 마지막 값을 고정해서? > >그냥 처음값만 고정하고 마지막은 뭐 필요없을듯