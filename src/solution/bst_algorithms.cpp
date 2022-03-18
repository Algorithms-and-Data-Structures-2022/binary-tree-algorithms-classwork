#include "classwork/bst_algorithms.hpp"

#include <cmath>  // max

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
}  // namespace classwork