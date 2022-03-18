#include "classwork/bst_algorithms.hpp"

#include <cmath>  // max, pow

namespace classwork {

  int compute_tree_height(Node* node) {
    if (node == nullptr) {
      return 0;
    }

    // поиск высоты левого и правого поддеревьев
    int left_subtree_height = compute_tree_height(node->left);
    int right_subtree_height = compute_tree_height(node->right);

    // высота = максимальная высота среди поддеревьев + 1 (корневой узел)
    return std::max(left_subtree_height, right_subtree_height) + 1;
  }

  int compute_tree_size(Node* node) {
    // Write you code here ...
    return 0;
  }

  std::vector<Node*> tree_as_array(Node* root) {
    // Write your code here ...
    return {};  // пустой массив
  }

  void tree_as_array_helper(int node_idx, Node* node, std::vector<Node*>& arr) {
    // Write your code here ...
  }

}  // namespace classwork