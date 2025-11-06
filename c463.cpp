#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

struct Node {
    int data;
    vector<Node*> kids;
    Node(int v) : data(v) {};
};

map<int, Node*> deroot;
Node* nothing = new Node(0);

void build(int i, vector<int> chi) {
    Node* par = new Node(i);
    deroot[i] = par;
    for (int v : chi) {
        Node* child = new Node(v);
        deroot[v] = nothing;
        par->kids.push_back(child);
    }
}

int dfs(Node* node) {
    int now = 0;
    if (node->kids.size() == 0)
        ans[node->data] = now; return now;
    for (auto ele : node->kids) {
        now = max(now, dfs(ele));
    }
    ans[node->data] = now;
    return now;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ans.assign(n+1, 0);

    Node* root = nullptr;
    for (int i = 1; i <= n; i++)
        deroot[i] = nothing;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        // if (k == 0) break;
        vector<int> chi(k);
        for (int j = 0; j < k; j++) cin >> chi[j];
        build(i, chi);
    }

    for (auto s : deroot) {
        if (s.second != nothing)
            root = s.second;
    }

    dfs(root);

    cout << root->data << " " << accumulate(ans.begin(), ans.end(), 0);

    return 0;
}
