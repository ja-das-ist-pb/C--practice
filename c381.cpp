#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    while (cin >> n >> m){
        if (n == 0 && m == 0) 
            break;
        string s = "";
        for (int i = 0; i < n; i++){
            string ss;
            cin >> ss;
            s += ss;
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cout << s[x-1];
        }
        cout << endl;
    }
}