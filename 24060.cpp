#include <iostream>
#include <vector>
using namespace std;

int num = 0;
bool out = true;
int k;
void merge(vector<int>& A, int p, int q,int r)
{
	int i = p; int j = q + 1; int t = 0;
	vector<int> tmp(r - p + 1);
	while (i <= q && j <= r)
	{
		if (A[i] <= A[j]) 
		{
			tmp[t++] = A[i++];
			if (k == ++num)
			{
				cout << tmp[t - 1];
				out = false;
			}

		}
		else 
		{
			tmp[t++] = A[j++];
			if (k == ++num)
			{
				cout << tmp[t - 1];
				out = false;
			}

		}
	}
	while (i <= q) 
	{
		tmp[t++] = A[i++];
		if (k == ++num)
		{
			cout << tmp[t - 1];
			out = false;
		}


	}
	while (j <= r) 
	{
		tmp[t++] = A[j++];
		if (k == ++num)
		{
			cout << tmp[t - 1];
			out = false;
		}

	}
	i = p;t = 0;
	while (i <= r) A[i++] = tmp[t++];
}

void merge_sort(vector<int>& A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}



int main()
{
	int n;
	cin >> n >> k;
	vector<int> A(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	merge_sort(A, 0, (A.size() - 1));

	if (out) cout << -1;
}