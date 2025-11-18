//사다리를 역순으로 올라간다
//왼오, 위 이렇게 3방향으로만 가능 
//마지막	에 y좌표가 0이면 그때의 x가 답

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 10;
	while (n--)
	{
		int test;
		cin >> test;
		int arr[100][100];
		int goalX, goalY;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				int tmp;
				cin >> tmp;
				arr[i][j]=tmp;
				if (tmp == 2)
				{
					goalX = j;
					goalY = i;
				}
			}
		}

		while (goalY)
		{
			if (goalX-1 >=0 &&arr[goalY][goalX-1] == 1)
			{
				arr[goalY][goalX] = 0;
				goalX--;
			}
			else if (goalX+1 < 100 && arr[goalY][goalX + 1] == 1)
			{
				arr[goalY][goalX] = 0;
				goalX++;
			}
			else
			{
				goalY--;
			}
		}

		cout << "#" << test << " " << goalX << "\n";
	}
}