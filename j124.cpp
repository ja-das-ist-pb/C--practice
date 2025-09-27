#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;
int pos = 0;
long long ans = 0;

struct node{
    int data;
    vector<node*> children;
    node(int v): data(v) {};
};

node *build() {
    if (pos >= n) return nullptr;

    int data = a[pos++];
    node *nnode = new node(data);
    if (data == 0) return nnode;

    int childcount;
    if (data % 2 == 0) childcount = 2;
    else childcount = 3;

    for (int i = 0; i < childcount; i++) {
        if (pos < n) {
            node *child = build();
            nnode->children.push_back(child);
        }
    }

    return nnode;
}

void dfs(node *Node) {
    for(auto child : Node->children) {
        if (child->data == 0) continue;
        else {
            dfs(child);
            ans += abs(Node->data - child->data);
        }
    }
}

int main() {
    int x;
    while(cin >> x) a.push_back(x);
    n = a.size();
    node *root = build();
    dfs(root);
    cout << ans;
}