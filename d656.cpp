#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int i = 1;
    while (cin >> n) {
        if (n == 0) 
            break;
        cout << "Case " << i << ": " << n / 2 << endl;
        i++;
    }
}