#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> dp(1000, vector<int>(1000, 0));
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) 
            dp[i][0] = s[0] - '0';
        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; j < s.size(); j++) {
                dp[i][j] = dp[i][j-1] + (s[j] - '0');
            }
        }
        int m = 0;
        for (int i = 0; i < s.size(); i++) {
            m = max(m, *max_element(dp[i].begin(), dp[i].end()));
        }
        cout << m << endl;
    }
}