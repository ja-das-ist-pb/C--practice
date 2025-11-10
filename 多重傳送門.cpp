#include <bits/stdc++.h>
using namespace std;

struct trans {
    int y;
    int x;
};

struct pos {
    int y;
    int x;
    int step;
};

map<char, vector<trans>> tran;
trans start;
trans end;
vector<vector<char>> a;
vector<vector<bool>> walked;

queue<pos> q;
vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
q.push({start.y, start.x, 0});
walk[start.y][start.x] = true;

int bfs() {
    while (!q.empty()) {
        pos now = q.front();
        q.pop();
        for (auto dir : d){
            int ny = now.y + dir[0];
            int nx = now.x + dir[1];

            if (a[ny][nx] != 1 and walked[ny][nx] == false) {
                if (a[ny][nx] != 0){
                     if ({ny, nx} != tran[a[ny][nx]][0]) {
                        ny = tran[a[ny][nx]][0][0];
                        nx = tran[a[ny][nx]][0][1];
                     }
                     else {
                        ny = tran[a[ny][nx]][1][0];
                        nx = tran[a[ny][nx]][1][1];
                     }
                }
                q.push({ny, nx, now.pos++});
                walked[ny][nx] = true;
            }

        }
    }


}

int main() {
    int n, m;
    cin >> n >> m;
    a.assign(n+2, vector<char> (m+2));
    walked.assign(n+2, vector<char> (m+2), false);
    for (int i = 0; i < n+2; i++){
        a[i][0] = 1; a[i][m+1] = 1;}
    for (int j = 0; j < m+2; j++) {
        a[0][j] = 1; a[n+1][j] = 1;}

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '@')
                start = {i, j};
            else if (a[i][j] == '%')
                end = {i ,j};
            else if (a[i][j] != '0' && a[i][j] != '1')
                tran[a[i][j]].push_back({i, j});
        }

    cout << bfs();
}
