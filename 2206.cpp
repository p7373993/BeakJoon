#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <climits>   // INT_MAX
using namespace std;

static int distArr[1000][1000][2]; // 0: 안 부숨, 1: 한 번 부숨

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> g(N);
    for (int i = 0; i < N; ++i) cin >> g[i];

    // 0은 미방문 표시
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            distArr[y][x][0] = distArr[y][x][1] = 0;

    queue<tuple<int, int, int>> q; // y, x, broke
    distArr[0][0][0] = 1;
    q.emplace(0, 0, 0);

    const int dy[4] = { -1, 1, 0, 0 };
    const int dx[4] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        auto [y, x, b] = q.front(); q.pop();

        if (y == N - 1 && x == M - 1) {
            cout << distArr[y][x][b] << "\n"; // BFS라 첫 도달이 최단
            return 0;
        }

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            if (g[ny][nx] == '0') {
                if (distArr[ny][nx][b] == 0) {
                    distArr[ny][nx][b] = distArr[y][x][b] + 1;
                    q.emplace(ny, nx, b);
                }
            }
            else { // '1' 벽
                if (b == 0 && distArr[ny][nx][1] == 0) {
                    distArr[ny][nx][1] = distArr[y][x][0] + 1;
                    q.emplace(ny, nx, 1);
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
