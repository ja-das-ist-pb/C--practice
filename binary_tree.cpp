#include <bits/stdc++.h>
using namespace std;

struct node {
    int data; 
    node *left = nullptr, *right = nullptr;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    node *root = new node();
    root -> data = a[0];
    for (int i = 1; i < n; ++i) {
        node *nnode = new node();
        nnode -> data = a[i];
        node *ptr = root;
        node *backup = ptr;
        while (ptr != nullptr) {
            backup = ptr;
            if (nnode -> data < ptr -> data) {
                ptr = ptr -> left;
            }
            else {
                ptr = ptr -> right;
            }
        }
        if (nnode -> data < backup -> data)
            backup -> left = nnode;
        else 
            backup -> right = nnode;

    }
}