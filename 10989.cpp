#include <iostream>
#include <cstdio> // printf�� ����ϱ� ���� ����

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int vec[10001] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        vec[m]++;
    }
    for (int i = 0; i <= 10000; i++) {
        while (vec[i] > 0) {
            vec[i]--;
            cout << i << '\n'; // printf�� ����Ͽ� ��� ���� ���
        }
    }

    return 0;
}