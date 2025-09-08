#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int64 k;                 // k도 long long
    cin >> n >> k;

    vector<int64> A(n);      // 길이도 long long
    for (int i = 0; i < n; ++i) cin >> A[i];

    int64 lo = 1;
    int64 hi = *max_element(A.begin(), A.end());
    int64 ans = 0;

    while (lo <= hi) {
        int64 mid = lo + (hi - lo) / 2;   // 안전한 중간값
        int64 sum = 0;

        // 조기 종료: k 이상이면 더 셀 필요 없음
        for (int i = 0; i < n; ++i) {
            sum += A[i] / mid;
            if (sum >= k) break;
        }

        if (sum >= k) {      // 가능 → 더 길게 시도
            ans = mid;
            lo = mid + 1;
        }
        else {             // 불가능 → 더 짧게
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
