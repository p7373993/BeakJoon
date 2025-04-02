#include <iostream>
#include <cstdio> // printf를 사용하기 위해 포함

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
            cout << i << '\n'; // printf를 사용하여 출력 성능 향상
        }
    }

    return 0;
}