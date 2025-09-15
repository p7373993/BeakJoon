#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long count(long long num,long long n)
{
	long long ct = 0;
	for (long long i = 1; i <= n; i++)
	{
		ct += min(n, (num/i));
	}

	return ct;
}

int main()
{
	//3*3 10,000,000,000
	//1 2 2 3 3 4 6 6 9
	// 아마 값을 찾는거 보단 넣는거를 logn으로 바꿀 방법이 필요할듯 
	//넣는다는것도 최소 10억인데 2초 안에 불가능
	//즉 값을 넣고 거기 인덱스 찾는게 아니라 
	//k값을 보고 그자리르 유추를 해야한다
	//지금껏 이분탐색 문제는 정답 값을 정하고 가능 여부에 따라 재탐색을 하는 방식이였음
	// 그러면 B[k]는 lo, hi로 일단 정의를 해야하는데 lo,hi는 뭘까 1, n*n? 그럼 mid 는 저사이고
	// mid 를 구하고 이게 k번째에 해당하는지는? 이건 n에따라 뭔가 달라질듯
	// if n = 2 > 1 2 2 4 / 규칙이있나?
	//n = 3 > 1 2 2 3 3 4 6 6 9
	// n= 4 > 1 2
	// 
	//ct(x) = min(n,x/i)
	//그러면 ct 갯수를 미리 정하고 위식으로 계속 검증
	long long  n;
	long long k;
	cin >> n >> k;

	long long lo = 1;
	long long hi = n * n;
	long long ans = 0;

	while(lo <= hi)
	{
		long long mid = lo + (hi - lo) / 2;
		long long ct;
		ct = count(mid, n);

		if (ct < k)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
			ans = mid;

		}
	}

	cout << ans;
}