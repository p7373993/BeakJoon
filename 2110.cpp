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
//C�� ��ġ�� ��� �װ� ������� �Ÿ� d�� ���ҷ��� �غôµ� ���̾���
// gpt���� ��Ʈ�޶��ϴ� �ִ� �Ÿ� d�� ���� �����ϰ� d�� �������� �ƴ����� ���� �̺�Ž�� ����


//��� ? lo + hi /2 �� d ����? �� �κ��� ������ �����ҵ�
//���� ������ �����Ұ� ������ ��ǥ���� ���� ���ɿ��� �����ϵ� << ��� ����
// num[i] + d < num[i+a] �ϰ� num[i+a] + d <num[j] �̰Ÿ� c�� �ݺ��� �Ǵ°��� üũ �ϱ�
//�׷��� ����ΰ� ó�� ������ ���� �����ؼ�? > >�׳� ó������ �����ϰ� �������� �� �ʿ������