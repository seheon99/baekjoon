#include <iostream>

struct node {
    struct node *left;
    struct node *right;
    char data;

    node(char data = 0) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void print_vlr(struct node *root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data;
    print_vlr(root->left);
    print_vlr(root->right);
}

void print_lvr(struct node *root) {
    if (root == nullptr) {
        return;
    }
    print_lvr(root->left);
    std::cout << root->data;
    print_lvr(root->right);
}

void print_lrv(struct node *root) {
    if (root == nullptr) {
        return;
    }
    print_lrv(root->left);
    print_lrv(root->right);
    std::cout << root->data;
}

int main(void) {
    struct node root[26];
    for (int i = 0; i < 26; i++) {
        root[i].data = 'A' + i;
    }

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        char data, left, right;
        std::cin >> data >> left >> right;
        if (left != '.') {
            root[data - 'A'].left = &root[left - 'A'];
        }
        if (right != '.') {
            root[data - 'A'].right = &root[right - 'A'];
        }
    }

    print_vlr(root);
    std::cout << std::endl;
    print_lvr(root);
    std::cout << std::endl;
    print_lrv(root);
    std::cout << std::endl;
    return 0;
}
