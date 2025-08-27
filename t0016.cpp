#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int tot = m / (9 * n) * 10 + (m % (9 * n)) / n;
    int stick = tot;
    while (stick >=5) {
        int extra = stick / 5;
        tot += extra;
        stick = stick % 5 + extra;
    }
    cout << tot;
}