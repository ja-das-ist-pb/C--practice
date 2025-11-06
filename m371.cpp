#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;

int match(int n, int m){
    int score = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s.insert(a[i][j]);
        }
    }
    if (s.find(-1) != s.end()) {
        s.erase(-1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if 
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    a.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    int score;

    while (score != 0) {
        score = 0;
        score = match(n, m);
        ans+=score;
    }

}