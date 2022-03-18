#include "classwork/binary_search_tree.hpp"

#include <iostream>  // cout

namespace classwork {

  BinarySearchTree::~BinarySearchTree() {
    clear(root_);
    root_ = nullptr;
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key, value, root_);
  }

  void BinarySearchTree::Traverse(TraversalStrategy* strategy) const {
    strategy->Print(root_, std::cout);
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {

    if (node == nullptr) {
      node = new Node(key, value);
      return;
    }

    if (key == node->key) {
      node->value = value;
      return;
    }

    if (key < node->key) {
      insert(key, value, node->left);
    } else {
      insert(key, value, node->right);
    }
  }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

}  // namespace classwork