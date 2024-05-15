//
// Created by Filip Persson on 2024-05-07.
//

#ifndef LABB3_BINARY_TREE_H
#define LABB3_BINARY_TREE_H

#include <memory>
#include <vector>

struct Node {
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    std::unique_ptr<Node> root;
public:
    explicit BinaryTree(const std::vector<int>& arr) : root(recursiveInsert(arr, 0, arr.size())) {}
    Node *recursiveInsert(const std::vector<int> &arr, int start, int end);
    bool search(int target);
};


#endif //LABB3_BINARY_TREE_H
