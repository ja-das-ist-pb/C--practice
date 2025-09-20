#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k, r, c;
    cin >> m >> n >> k >> r >> c;
    vector<vector<int>> a(m+2, vector<int>(n+2, -1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ny = r + 1, nx = c + 1;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int nd = 0;
    int score = 0;
    int ans = 0;
    score += a[ny][nx];
    a[ny][nx] -= 1;
    ans += 1;

    while (true) {
        if (score % k == 0 && score > 0) {
            nd = (nd + 1) % 4;
        }

        while (a[ny + d[nd][0]][nx + d[nd][1]] == -1) {
            nd = (nd + 1) % 4;
        }

        ny += d[nd][0];
        nx += d[nd][1];

        if (a[ny][nx] == 0){
            break;
        }

        score += a[ny][nx];
        a[ny][nx] -= 1;
        ans += 1;
    }
    cout << ans;
}