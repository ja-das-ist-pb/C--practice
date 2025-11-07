#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100001];
int maxdis = 0;

int dfs(int node) {
    int nd = 0;
    vector<int> chidep;
    if (tree[node].size() == 0)
        chidep.push_back(nd);
    for (int v : tree[node]) {
        int child;
        child = dfs(v) + 1;
        chidep.push_back(child);
        nd = max(nd, child);
    }

    int distance;
    if (chidep.size() == 0)
        distance = 0;
    else if (chidep.size() == 1)
        distance = chidep[0];
    else {
        sort(chidep.rbegin(), chidep.rend());
        distance = chidep[0] + chidep[1];
    }
    maxdis = max(maxdis, distance);

    return nd;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int deroot[n] = {};
    int root;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        deroot[b]++;
        tree[a].push_back(b);
    }
   
    for (int i = 0; i < n; i++){
        if (deroot[i] ==0) {
            root = i; 
            break;
        }
    }

     dfs(root);

    // cout << root;

    cout << maxdis;

    return 0;

}
