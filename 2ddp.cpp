#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int dp(vector<vector<int>> &a) {
    int trans[n][m];
    trans[0][0] = a[0][0];
    for(int i = 1; i < n; i++)
        if (a[i][0] + trans[i-1][0] < q)
            trans[i][];
        else if (a[i][0] + trans[i-1][0] < q)
            trans[i][0] = a[i][0] + trans[i-1][0];
        else 
            trans[i][0] = q;
    for (int i = 1; i < m; i++) 
        if (a[0][i] + trans[0][i-1] < q)
            trans[0][i] = a[0][i] + trans[0][i-1];
        else
            trans[0][i] = q;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] + min(trans[i-1][j], trans[i][j-1]) < q)
                trans[i][j] = a[i][j] + max(trans[i-1][j], trans[i][j-1]);
            else 
                trans[i][j] = q;
        }
    }
    if (trans[n-1][m-1] < 0) 
        return 0;
    return trans[n-1][m-1];
}

int main() {
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
    }
    cout << dp(a);
}
// test data : 3, 5, 6  didn't pass