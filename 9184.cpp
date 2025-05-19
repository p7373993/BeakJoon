#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//w배열을 3차원으로?vec<vec<vec<int>>>


int w(vector<vector<vector<int>>>& vec, int a, int b, int c)
{

	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	if (a > 20 || b > 20 || c > 20)
	{
		return w(vec, 20, 20, 20);
	}
	if (a < b && b < c)
	{
		if (vec[a][b][c - 1] == -1)
		{
			vec[a][b][c - 1] = w(vec, a, b, c - 1);
		}
		if (vec[a][b - 1][c - 1] == -1)
		{
			vec[a][b - 1][c - 1] = w(vec, a, b - 1, c - 1);
		}
		if (vec[a][b - 1][c] == -1)
		{
			vec[a][b - 1][c] = w(vec, a, b - 1, c);
		}
		return (vec[a][b][c - 1]) + (vec[a][b - 1][c - 1]) - (vec[a][b - 1][c]);
	}
	else
	{
		if (vec[a - 1][b][c] == -1) vec[a - 1][b][c] = w(vec, a - 1, b, c);
		if (vec[a - 1][b - 1][c] == -1) vec[a - 1][b - 1][c] = w(vec, a - 1, b - 1, c);
		if (vec[a - 1][b][c - 1] == -1) vec[a - 1][b][c - 1] = w(vec, a - 1, b, c - 1);
		if (vec[a - 1][b - 1][c - 1] == -1) vec[a - 1][b - 1][c - 1] = w(vec, a - 1, b - 1, c - 1);


		return (vec[a - 1][b][c]) + (vec[a - 1][b - 1][c]) + (vec[a - 1][b][c - 1]) - (vec[a - 1][b - 1][c - 1]);
	}



}
int main()
{
	int a, b, c;
	int num;
	vector<int> f(21, -1);
	vector<vector<int>> s(21, f);
	vector<vector<vector<int>>>t(21, s);
	while (cin >> a >> b >> c)
	{


		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = ";

		num = w(t, a, b, c);

		cout << num << "\n";
	}
	//t[a, b, c];
	//t[0, :, : ] = 0;
	//t[:, 0, : ] = 0;
	//t[:, : , 0] = 0;

}