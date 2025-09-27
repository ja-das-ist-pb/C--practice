#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;

struct node{
    int p;
    int c;
};

int bfs () {
    int ans = 0;
    queue<node> q;
    q.push({0, 0});
    vector<int> cost;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        int p = now.p;
        int c = now.c;
        if (p == n-1) {
            cost.push_back(c);
        }
        for (int i = 0; i < n; i++) {
            if (a[p][i] != 0) {
                q.push({i, c + a[p][i]});
            }
        }
    }

    ans = *min_element(cost.begin(), cost.end());

    return ans;
}

int main() {
    cin >> n;
    a.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>> a[i][j];
        }
    }

    cout << bfs();
}