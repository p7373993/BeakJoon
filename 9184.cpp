#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//w�迭�� 3��������?vec<vec<vec<int>>>
int main()
{
	int a, b, c;
	cin >> a >> b >> c;


	vector<int> f(a,1);
	vector<vector<int>> s(b, f);
	vector<vector<vector<int>>>t(a, s);



}