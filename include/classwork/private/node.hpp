#pragma once

namespace classwork {

  struct Node final {

    int key;
    int value;

    Node* left{nullptr};
    Node* right{nullptr};

    Node(int key, int value) : key{key}, value{value} {}
  };

}  // namespace classwork