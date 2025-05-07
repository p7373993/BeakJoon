#include <iostream>
#include <vector>
#include <set>
using namespace std;

int bpos[16][16];
vector<pair<int,int>> vec;
set<int> x;
set<int> y;
int sizes = 0;
int counts=0;
int n;
//벡터를 두개 놔서 해당 열은 삭제 시ㅕ 버리기?
void back(int m)
{
	if (sizes == n)
	{
		counts++;
		return;
	}
	int i = m;
	for (int j = 1; j <= n; j++)
		{
			if (bpos[i][j] == 0)
			{
				for (size_t k = 1; k <= n; k++)
				{
					++bpos[i][k];
				}
				for (size_t k = 1; k <= n; k++)
				{
					++bpos[k][j];
				}
				--bpos[i][j];
				//x.emplace(j);

				int a = i;
				int b = j;
				while (1)
				{
					if (a == n || b == n) break;
					++bpos[++a][++b];

				}
				a = i;
				b = j;
				while (1)
				{
					if (a == n || b == 1) break;
					++bpos[++a][--b];
				}
				//vec.emplace_back( i,j );
				++sizes;
				back(i + 1);
				--sizes;
				//vec.pop_back();
				for (size_t k = 1; k <= n; k++)
				{
					--bpos[i][k];
				}
				for (size_t k = 1; k <= n; k++)
				{
					--bpos[k][j];
				}
				++bpos[i][j];
				//x.extract(j);
				a = i;
				b = j;
				while (1)
				{
					if (a == n || b == n) break;
					--bpos[++a][++b];
				}
				a = i;
				b = j;
				while (1)
				{
					if (a == n || b == 1) break;
					--bpos[++a][--b];
				}


			}
		}
}
int main()
{
	cin >> n;
	back(1);

	cout << counts;


}