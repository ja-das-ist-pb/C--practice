
#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<vector<int>> a;
vector<vector<int>> trans;

int dp() {
    if (a[0][0] > 0)
        trans[0][0] = a[0][0];
    else
        trans[0][0] = 0;

    bool canpass = true;
    for(int i = 1; i < n; i++){
        if (a[i][0] == -99) {
            canpass = false;
        }
        if (!canpass) {
            a[i][0] = -99;
        }
        else if (a[i][0] + trans[i-1][0] < 0)
            trans[i][0] = 0;
        else if (a[i][0] + trans[i-1][0] < q)
            trans[i][0] = a[i][0] + trans[i-1][0];
        else
            trans[i][0] = q;
    }
    canpass = true;

    for (int i = 1; i < m; i++){
        if (a[0][i] == -99) {
            canpass = false;
        }
        if (!canpass) {
            a[0][i] = -99;
        }
        if (a[0][i] + trans[0][i-1] < 0)
            trans[0][i] = 0;
        else if (a[0][i] + trans[0][i-1] < q)
            trans[0][i] = a[0][i] + trans[0][i-1];
        else
            trans[0][i] = q;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] == -99) {
                trans[i][j] = 0;
                continue;
            }
            if (a[i-1][j] == -99 && a[i][j-1] == -99) {
                trans[i][j] = 0;
                continue;
            }
            if (a[i][j] + max(trans[i-1][j], trans[i][j-1]) < 0)
                trans[i][j] = 0;
            else if (a[i][j] + max(trans[i-1][j], trans[i][j-1]) < q)
                trans[i][j] = a[i][j] + max(trans[i-1][j], trans[i][j-1]);
            else
                trans[i][j] = q;
        }
    }

    return trans[n-1][m-1];
}

int main() {
    cin >> n >> m >> q;
    a.assign(n, vector<int>(m));
    trans.assign(n, vector<int>(m));
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    cout << dp() << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<< a[i][j] << "\t";
        }
        cout<< endl;
    }
    cout<< endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<< trans[i][j] << "\t";
        }
        cout<< endl;
    }
}
// test data :  5, 6  didn't pass
