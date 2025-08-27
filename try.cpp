#include <bits/stdc++.h>
using namespace std;

int n, a[2][3], b[2][3], c[2][3];

void astep() {
    a[1][0] = ceil(float(a[0][1]) / n) + ceil(float(a[0][2]) / n);
    a[1][1] = ceil(float(a[0][0]) / n) + ceil(float(a[0][2]) / n);
    a[1][2] = ceil(float(a[0][0]) / n) + ceil(float(a[0][1]) / n);
}

void bstep() {
    b[1][0] = ceil(float(b[0][1]) / n) + ceil(float(b[0][2]) / n);
    b[1][1] = ceil(float(b[0][0]) / n) + ceil(float(b[0][2]) / n);
    b[1][2] = ceil(float(b[0][0]) / n) + ceil(float(b[0][1]) / n);
}

void cstep() {
    c[1][0] = ceil(float(c[0][1]) / n) + ceil(float(c[0][2]) / n);
    c[1][1] = ceil(float(c[0][0]) / n) + ceil(float(c[0][2]) / n);
    c[1][2] = ceil(float(c[0][0]) / n) + ceil(float(c[0][1]) / n);
}

int main() {
    cin >> n;
    for (int i = 0; i < 3; i++){
        cin >> a[0][i] >> b[0][i] >> c[0][i];
    }

    astep();
    bstep();
    cstep();
    
    int ans[6] = {
        a[1][0] + b[1][1] + c[1][2], 
        a[1][0] + b[1][2] + c[1][1],
        a[1][1] + b[1][0] + c[1][2],
        a[1][1] + b[1][2] + c[1][0],
        a[1][2] + b[1][0] + c[1][1],
        a[1][2] + b[1][1] + c[1][0]
    };
    sort(ans, ans+6);
    cout << ans[0]; 
}