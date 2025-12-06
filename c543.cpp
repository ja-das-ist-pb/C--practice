#include <bits/stdc++.h>
using namespace std;

int mod = pow(10, 9) + 7;
vector<vector<int>> dp(10, vector<int>(100000 + 5, 1));

int sum(int b, int e, int col) {
    long long re = 0;
    for (int i = b; i <= e; i++) {
        re += dp[i][col];
        re = re % mod;
    }
    return re;
}

bool increasing(string s) {
    int f = s[0] - '0';
    for (int i = 1; i < s.size(); i++) {
        if ((s[i]-'0') < f)
            return false;
    }
    return true;
}

// this is for accumulating
// int  acc()

int main() {
    string s;

    // finish dp first
    for (int len = 2; len < 100000+6; len++) {
        for (int f = 8; f > 0; f--) {
            long long x = dp[f+1][len] + dp[f][len-1];
            dp[f][len] = x % mod;
        }
    }

    while (cin >> s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int f = int(s[i]) - 48;
            
            for (int i = 1; i < n-1; i++) {
                ans += sum(1, 9, i);
                ans = ans % mod;
            }

            //int h = (increasing(s)) ? f : f-1;
            for (int i = 1; i < f-1; i++) {
                for (int j = 0; j < n-1; j++) {
                    ans += sum(i, 9, j);
                    ans = ans % mod;
                }
            }

            if (increasing(s)) {

            }

            ans = ans % mod;
        }
        cout << ans << endl;
    }
}