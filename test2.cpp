#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int a[n][n];
    vector<int> loop;
    int move = n -1;
    int fake_move = move;
    int d = 0;
    int nx = 0;
    int ny = 0;

    while (fake_move > 0) {
        loop.push_back(fake_move);
        fake_move -= 2;
    }
    int suml = accumulate(loop.begin(), loop.end(), 0);
    if (suml * 4 < n * n){
        loop.push_back(n * n - suml * 4);
    }
    for (int x : loop) {
        cout << x << " ";
    }
    
    for (int i = 0; i < loop.size(); i++) {
        for (int j = 0; j < loop[i]; j++) {
            a[ny][nx] = s;
            s += 1;
            ny += direction[d][0];
            nx += direction[d][1];
        }
        d = (d + 1) % 4;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}