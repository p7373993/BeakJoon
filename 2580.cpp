//구멍이 하나인곳부터 시작??
//행열 단위로 구멍 하나 채우고 그다움에 네모 안 채우기
#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;
int sudocu[9][9];
int row[9];
int col[9];
int square[3][3];
vector<set<int>> row_v(9,{1,2,3,4,5,6,7,8,9});
vector<set<int>> col_v(9, { 1,2,3,4,5,6,7,8,9 });
vector<set<int>> square_v(9, { 1,2,3,4,5,6,7,8,9 });

queue <pair<int, int>> se;

void back()
{
	if (se.size() == 0) return;

	auto [a,b] = se.front();
	se.pop();
	if (row_v[a].size() == 1)//이렇게 사이즈로 나머지 다바꾸기
	{
		for (auto& v : row_v[a])
		{
			sudocu[a][b] = v;
			++row[a];
			++col[b];
			++square[a / 3][b / 3];
			row_v[a].extract(v);
			col_v[b].extract(v);
			square_v[a / 3 + b / 3].extract(v);
		}
		back();
	}
	else if (col[b] == 1)
	{
		for (auto& v : col_v[b])
		{
			sudocu[a][b] = v;
			++row[a];
			++col[b];
			++square[a / 3][b / 3];

		}
		back();
	}
	else if (square[a / 3][b / 3] == 1)
	{
		for (auto& v : square_v[a / 3 + b / 3])
		{
			sudocu[a][b] = v;
			++row[a];
			++col[b];
			++square[a / 3][b / 3];

		}
		back();
	}
	
	se.emplace(a, b);
}
int main()
{
	for (size_t i = 0; i < 81; i++)
	{
		int num;
		cin >> num;
		int a = i / 9;
		int b = i % 9;
		if (num == 0)
		{

			se.emplace( a, b);
			++row[a];
			++col[b];
			++square[a / 3][b / 3];
		}
		row_v[a].extract(num);
		col_v[b].extract(num);
		square_v[a/3 + b/3].extract(num);
		sudocu[a][b] = num;
	}
	back();
	for (size_t i = 0; i < 81; i++)
	{
		if (i % 9 == 0) cout << "\n";
		cout << sudocu[i / 9][i % 9]<<" ";
	}
}