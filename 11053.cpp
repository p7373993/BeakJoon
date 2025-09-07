//		gpt 도움받음
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nums[1001];
int dp[1001];
vector<int> a;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1; // 최소 길이 1
        for (int j = 1; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result;
}