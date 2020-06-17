#include <iostream>
#include <assert.h>

using namespace std;

struct node {
    node *l;
    node *r;
    int value;
    int count_l;
    int count_r;
};

void fill(node *root, int *arr, int n) {
    assert(n > 0);
    if (n == 1) {
        root->value = arr[0];
        root->l = NULL;
        root->r = NULL;
        root->count_l = 0;
        root->count_r = 0;
    } else {
        int m = n / 2;
        root->count_l = m;
        root->l = new node();
        fill(root->l, arr, root->count_l);

        root->count_r = n - m;
        root->r = new node();
        fill(root->r, arr + m, root->count_r);
    }
}

int get_ith(node *root, int i) {
    if (root->l == NULL) {
        return root->value;
    } else if (i < root->count_l) {
        return get_ith(root->l, i);
    } else {
        return get_ith(root->r, i - root->count_l);
    }
}

void remove_ith(node *root, int i) {
    if (root->l == NULL) {
    } else if (i < root->count_l) {
        remove_ith(root->l, i);
        root->count_l--;
    } else {
        remove_ith(root->r, i - root->count_l);
        root->count_r--;
    }
}

void print_tree(node *root, int shift = 0) {
    for (int i = 0; i < shift; i++) cout << "| ";
    cout << "|-";
    cout << "value:" << root->value << " count_l:" << root->count_l << " count_r:" << root->count_r << " l:" << root->l
         << " r:" << root->r << endl;
    if (root->l) {
        print_tree(root->l, shift + 1);
    }
    if (root->r) {
        print_tree(root->r, shift + 1);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
    node *root = new node();
    fill(root, arr, n);
//    print_tree(root);
//    for (int i = 0; i < n; i++) {
//        cout << get_ith(root, i) << " ";
//    }
//    cout << endl;
    int pos = k - 1;
    for (int i = 0; i < n; i++) {
        pos = pos % (root->count_l + root->count_r + (root->l ? 0 : 1));
        cout << get_ith(root, pos) << " ";
        remove_ith(root, pos);
        pos += k - 1;
    }
    cout << endl;
    return 0;
}