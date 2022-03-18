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

  int compute_tree_size(Node* node) {
    // Write you code here ...

    if (node == nullptr) {
      return 0;
    }

    // вычисление размера левого и правого поддеревьев
    int left_subtree_size = compute_tree_size(node->left);
    int right_subtree_size = compute_tree_size(node->right);

    // размер = размер левого поддерева + размер правого поддерева + 1 (корневой узел)
    return left_subtree_size + right_subtree_size + 1;
  }

  std::vector<Node*> tree_as_array(Node* root) {

    if (root == nullptr) {
      return {};  // пустой массив
    }

    // вычисляем высоту дерева
    int tree_height = compute_tree_height(root);

    // подсчитываем МАКСИМАЛЬНЫЙ размер дерева
    int tree_max_size = static_cast<int>(std::pow(2, tree_height) - 1);

    // создаем массив из tree_max_size nullptr'ов
    std::vector<Node*> arr(tree_max_size, nullptr);

    // задаем корневой узел
    arr[0] = root;

    // запускаем процесс преобразования дерева в массив с корневого узла
    tree_as_array_helper(0, root, arr);

    return arr;
  }

  void tree_as_array_helper(int node_idx, Node* node, std::vector<Node*>& arr) {

    if (node == nullptr) {
      return;
    }

    // вычисляем индексы левого и правого потомков в массиве
    int left_child_idx = 2 * node_idx + 1;
    int right_child_idx = 2 * node_idx + 2;

    // останавливаем процесс в случае выхода за пределы массива
    if (left_child_idx >= arr.size()) {
      return;
    }

    // копируем левый и правый узлы в массив
    arr[left_child_idx] = node->left;
    arr[right_child_idx] = node->right;

    // запускаем рекурсивный процесс для левого и правого поддерева
    tree_as_array_helper(left_child_idx, node->left, arr);
    tree_as_array_helper(right_child_idx, node->right, arr);
  }



}  // namespace classwork