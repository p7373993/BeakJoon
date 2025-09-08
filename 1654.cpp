#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int64 k;                 // k�� long long
    cin >> n >> k;

    vector<int64> A(n);      // ���̵� long long
    for (int i = 0; i < n; ++i) cin >> A[i];

    int64 lo = 1;
    int64 hi = *max_element(A.begin(), A.end());
    int64 ans = 0;

    while (lo <= hi) {
        int64 mid = lo + (hi - lo) / 2;   // ������ �߰���
        int64 sum = 0;

        // ���� ����: k �̻��̸� �� �� �ʿ� ����
        for (int i = 0; i < n; ++i) {
            sum += A[i] / mid;
            if (sum >= k) break;
        }

        if (sum >= k) {      // ���� �� �� ��� �õ�
            ans = mid;
            lo = mid + 1;
        }
        else {             // �Ұ��� �� �� ª��
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
