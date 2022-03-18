#pragma once

// динамический массив из стандартной библиотеки
#include <vector>

#include "classwork/private/node.hpp"  // Node

namespace classwork {

  /**
   * Вычисление высоты двоичного дерева.
   *
   * @param node - узел двоичного дерева
   * @return высота дерева
   */
  int compute_tree_height(Node* node);

  /**
   * Вычисление количества узлов в двоичном дереве.
   *
   * @param node - узел двоичного дерева
   * @return количество узлов в дереве
   */
  int compute_tree_size(Node* node);

  /**
   * Преобразование двоичного дерева в массив.
   *
   * Формулы преобразования:
   * - левый потомок: 2 * index + 1
   * - правый потомок: 2 * index + 2
   * - родитель: (index - 1) / 2
   *
   * Корневому узлу присваивается индекс 0.
   *
   * @param root - корневой узел двоичного дерева
   * @return массив узлов дерева
   */
  std::vector<Node*> tree_as_array(Node* root);

  /**
   * Вспомогательная функция для рекурсивного преобразования двоичного дерева в массив.
   *
   * @param node_idx - индекс текущего узла
   * @param node - указатель на текущий узел
   * @param arr - ссылка на массив, представляющего двоичное дерево
   */
  void tree_as_array_helper(int node_idx, Node* node, std::vector<Node*>& arr);

}  // namespace classwork