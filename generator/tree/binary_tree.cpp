//
// Created by Filip Persson on 2024-05-07.
//

#include "binary_tree.h"


bool searchHelper(std::unique_ptr<Node>& node, int target) {
    if (node == nullptr) {
        return false;
    }
    if (node->value == target) {
        return true;
    }
    if (node->value > target) {
        return searchHelper(node->left, target);
    } else {
        return searchHelper(node->right, target);
    }
}

bool BinaryTree::search(int target) {
    return searchHelper(root, target);
}

Node* BinaryTree::recursiveInsert(const std::vector<int>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    Node* node = new Node(arr[mid]);

    node->left.reset(recursiveInsert(arr, start, mid - 1));
    node->right.reset(recursiveInsert(arr, mid + 1, end));

    return node;
}
