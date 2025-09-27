#include <bits/stdc++.h>
using namespace std;

struct data {
    int x, y, h, step;
};

int n;

pair<int, int> bfs(vector<vector<int>>& a, int limit) {
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<data> q;
    vector<vector<bool>> walked(n, vector<bool>(n, false));
    data f = {0, 0, 0, 0};
    q.push(f);
    walked[0][0] = true;

    while (!q.empty()) {
        data now = q.front();
        q.pop();
        if (now.x == n - 1 && now.y == n - 1) {
            return {now.h, now.step};
        }

        bool pass = false;

        for (auto d : direction) {
            int nx = now.x + d.first;
            int ny = now.y + d.second;
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && !walked[ny][nx] && a[ny][nx] - a[now.y][now.x] <= limit) {
                pass = true;
                data after = {nx, ny, now.h, now.step + 1};
                if (a[ny][nx] - a[now.y][now.x] > now.h) {
                    after.h = a[ny][nx] - a[now.y][now.x];
                }
                q.push(after);
                walked[ny][nx] = true;
            }
        }

        if (!pass) {
            return {-1, 0};
        }
    }
    return {-1, 0};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int maxhight = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] > maxhight) {
                maxhight = a[i][j];
            }
        }
    }
    int top = maxhight, bot = 0;
    int h = 0, step = 0;

    while (bot < top) {
        int mid = (top + bot) / 2;
        auto package = bfs(a, mid);
        if (package.first == -1) {
            bot = mid + 1;
        } else {
            top = mid;
            h = package.first;
            step = package.second;
        }
    }

    cout << h << endl << step;
}