#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w1, w2, h1, h2;
    cin >> n >> w1 >> w2 >> h1 >> h2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int b1 = w1 * w1;
    int b2 = w2 * w2;
    int v1 = b1 * h1;
    int v2 = b2 * h2;

    int u1 = 0, u2 = 0;
    int prev = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        int v = a[i];

        int p1 = min(v, v1 - u1);
        u1 += p1;
        v -= p1;

        int p2 = min(v, v2 - u2);
        u2 += p2;
        v -= p2;

        int h = 0;
        if (u1 < v1) h = u1 / b1;
        else h = h1 + u2 / b2;

        ans = max(ans, h - prev);
        prev = h;
    }

    cout << ans;
}