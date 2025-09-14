#include <bits/stdc++.h>
using namespace std;

int howmany(string s) {
    stack<char> st;
    int tot = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (st.empty()) {
            st.push(s[i]);
        }
        else if (st.top() == '(' && s[i] == ')') {
            st.pop();
            tot += 1;
        }
        else {
            st.push(s[i]);
        }
    }
    if (st.empty())
        return tot;
    else 
        return 0;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << howmany(s) << endl;
    }
}