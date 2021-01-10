#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int key;
    int val;
    Node *left;
    Node *right;
    int height;
    int sum_val;
};

int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int sum_val(Node *N) {
    if (N == NULL)
        return 0;
    return N->sum_val;
}

Node *newNode(int key, int val) {
    Node *node = new Node();
    node->key = key;
    node->val = val;
    node->sum_val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    y->sum_val = y->val + sum_val(y->left) + sum_val(y->right);
    x->height = max(height(x->left), height(x->right)) + 1;
    x->sum_val = x->val + sum_val(x->left) + sum_val(x->right);
    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    x->sum_val = x->val + sum_val(x->left) + sum_val(x->right);
    y->height = max(height(y->left), height(y->right)) + 1;
    y->sum_val = y->val + sum_val(y->left) + sum_val(y->right);
    return y;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key, int val) {
    if (node == NULL)
        return (newNode(key, val));

    if (key < node->key)
        node->left = insert(node->left, key, val);
    else if (key > node->key)
        node->right = insert(node->right, key, val);
    else {
        node->val = val;
        node->sum_val = node->val + sum_val(node->left) + sum_val(node->right);
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    node->sum_val = node->val + sum_val(node->left) + sum_val(node->right);

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

pair<int, int> get_min_left_right(Node *node, int key) {
    int left_count = 0;
    int right_count = 0;
    while (true) {
        if (key < node->key) {
            right_count += sum_val(node->right) + node->val;
            node = node->left;
        } else if (node->key < key) {
            left_count += sum_val(node->left) + node->val;
            node = node->right;
        } else {
            break;
        }
    }
    return make_pair(left_count + sum_val(node->left), right_count + sum_val(node->right));
}

class Solution {
public:
    int createSortedArray(vector<int> &instructions) {
        unordered_map<int, int> counts;
        Node *root = NULL;
        int res = 0;
        for (auto num : instructions) {
            counts[num]++;
            root = insert(root, num, counts[num]);
            pair<int, int> lr = get_min_left_right(root, num);
//            cout << "num:" << num << " counts[num]:" << counts[num] << " l:" << lr.first << " r:" << lr.second << endl;
            res += min(lr.first, lr.second);
            res = res % (1000000000 + 7);
        }
        return res;
    }
};

int main() {
   {
       vector<int> inst = {1, 5, 6, 2};
       cout << Solution().createSortedArray(inst) << endl;
   }
   {
       vector<int> inst = {1, 2, 3, 6, 5, 4};
       cout << Solution().createSortedArray(inst) << endl;
   }
   {
       vector<int> inst = {1, 3, 3, 3, 2, 4, 2, 1, 2};
       cout << Solution().createSortedArray(inst) << endl;
   }
    return 0;
}