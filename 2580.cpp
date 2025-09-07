//������ �ϳ��ΰ����� ����??
//�࿭ ������ ���� �ϳ� ä��� �״ٿ� �׸� �� ä���
//�������� ���� ���� ������ ���ؼ� �ϱ�
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm> 
//set_intersection ���
using namespace std;
int sudocu[9][9];
int row[9];
int col[9];
int square[3][3];
vector<set<int>> row_v(9,set<int>{1,2,3,4,5,6,7,8,9});
vector<set<int>> col_v(9, set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});
vector<set<int>> square_v(9, set<int>{ 1,2,3,4,5,6,7,8,9 });
vector<pair<int, int>> blanks; // �� �� ��ġ ����
set<int> get_possible(int a, int b)
{
	set<int> temp, possible;
	set_intersection(row_v[a].begin(), row_v[a].end(),
		col_v[b].begin(), col_v[b].end(),
		inserter(temp, temp.begin()));

	set_intersection(temp.begin(), temp.end(),
		square_v[(a / 3) * 3 + b / 3].begin(), square_v[(a / 3) * 3 + b / 3].end(),
		inserter(possible, possible.begin()));

	return possible;
}
bool back(int idx)
{
	if (idx == blanks.size())
	{
		return true;
	}

	auto [a, b] = blanks[idx];
	
	set<int> possible = get_possible(a, b);

		for (auto v : possible) {
			
			sudocu[a][b] = v;
			row_v[a].erase(v); 
			col_v[b].erase(v);
			square_v[(a / 3) * 3 + b / 3].erase(v);

			if (back(idx+1)) return true;

			sudocu[a][b] = 0;
			row_v[a].insert(v);
			col_v[b].insert(v);
			square_v[(a / 3) * 3 + b / 3].insert(v);

		}


	
	
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 81; i++)
	{
		int num;
		cin >> num;
		int a = i / 9;
		int b = i % 9;
		if (num == 0)
		{
			blanks.emplace_back(a, b);
		}
		else 
		{
			row_v[a].erase(num);
			col_v[b].erase(num);
			square_v[(a / 3)*3 + b /3].erase(num);
			sudocu[a][b] = num;
		}

	}
	back(0);

	for (size_t i = 0; i < 81; i++)
	{
		if (i % 9 == 0) cout << "\n";
		cout << sudocu[i / 9][i % 9] << " ";
	}
}

