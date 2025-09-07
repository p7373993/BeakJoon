//11053 을 앞뒤 2개를 중첩
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nums[1001];
int dp[1001];
int dp_b[1001];
int dp_all[1001];
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
    }

    for (int i = n; i >= 1; i--) {
        dp[n] = 1; // 최소 길이 1
        for (int j = n; j > i; j--) {
            if (nums[j] < nums[i]) {
                dp_b[i] = max(dp_b[i], dp_b[j] + 1);
            }
        }
    }

    for (size_t i = 1; i <= n; i++)
    {
        dp_all[i] = dp[i] + dp_b[i];
        result = max(result, dp_all[i]);
    }

    

    cout << result;
}