#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;

struct data {
    int x, y, step;
};

pair<int, int> bfs(int h) {
    pair<int, int> re;
    queue<data> q;


    return {0, 0};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);




    int n; 
    cin >> n;
    a.assign(n+2, vector<int>(n+2, -1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            cin >> a[i][j];
        }
    }

    int top = 0, bottom = 0;
    for (vector<int> x : a) {
        if (top < *max_element(x.begin(), x.end())) {
            top = *max_element(x.begin(), x.end());
        }
    }

    while (bottom < top) {
        int mid = (bottom + top) / 2;
        
    }
}