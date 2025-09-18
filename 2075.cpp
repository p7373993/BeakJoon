//n*n모든 값을 정렬은 빡세다?
//n을 기반으로 무언가 식을 세우자
//일단 n개의 값을 넣는다 
//여기서 딱 n번쨰 숫자를 기반으로 그거 보단 큰거느 무시
//무시할떄 그열도 같이 무시

//는 큰거부터 해야하네 그러면 반대로?
//ex) 52 49 41 32 20+(48 35 28 25) > 52 49 48 41 35/여기서 자르기 그러면 n*n순회는 하겠지만 정렬을 안한다?
//O(2n*n) +a 


// 냅다 시작부터 pq하면 (n*n*logn)

//8바티으 * 100만은? 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	priority_queue<long long> pq;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<long long>> vec(n,vector<long long>(n));
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin>>vec[i][j];
		}
	}

	//끝 행 제일 작은거 기반으로 값 들어가게?
	//매 행마다 5번째 아래로는다 뽑아버리고 반복?
}