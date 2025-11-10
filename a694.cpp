#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n*n];
    for (int i = 0; i < n*n; i++) 
        cin >> a[i];
    int y1, x1, y2, x2;
    while (cin >> y1 >> x1 >> y2 >> x2) {
        int start = (y1 - 1) * n + x1;
        int end = (y2 - 1) * n + x2;
        int ans = 0;
        for (int i = start; i <= end; i++)
            ans += a[i];
        cout << ans << endl;
    }
}