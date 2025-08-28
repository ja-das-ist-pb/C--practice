#include <bits/stdc++.h>
using namespace std;

int n;

int count(string str[], int m){
    vector<int> v;

    for (int i = 0; i < n; i++) {
        set<char> s;
        string sub;
        vector<int> subv;
        for (int j = 0; i < m; j++) {
            sub += str[j][i];
            s.insert(str[j][i]);
        }
        for (char ch : s) {
            subv.push_back(count(sub.begin(), sub.end(), ch));
        }
        sort(subv.begin(), subv.end());
        v.push_back(subv.back());
    }
    return accumulate(v.begin(), v.end(), 0);
}

string spin(string s, int c) {
    if (c == 0) return s;

    else if (c > 0) {
        string front = s.substr(n - c, c);
        string back = s.substr(0, n - c);
        return front + back;
    }

    else {
        string front = s.substr(c, n - c);
        string back = s.substr(0, c);
        return front + back;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, k;
    cin >> m >> n >> k;
    string s[m];
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    int command[k][m];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> command[i][j];
        }
    }
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            s[j] = spin(s[j], command[i][k]);
        }
    }

    int tot = count(s, m);
    
}