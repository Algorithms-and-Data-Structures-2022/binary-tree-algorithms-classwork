#include <iostream>  // cout

#include "classwork/binary_search_tree.hpp"  // BinarySearchTree
#include "classwork/bst_algorithms.hpp"

using namespace classwork;
using std::cout;

int main() {

  // Построение дерева
  BinarySearchTree tree;

  /*
   *                 8
   *         3               10
   *     1     6         x      14
   *  x   x  4   7     x   x  13   x
   *
   * x - это nullptr
   */

  tree.Insert(8, 0);
  tree.Insert(3, 1);
  tree.Insert(10, 2);
  tree.Insert(1, 3);
  tree.Insert(6, 4);
  tree.Insert(14, 6);
  tree.Insert(4, 9);
  tree.Insert(7, 10);
  tree.Insert(13, 13);

  // Вычисление высоты дерева
  cout << "Tree height: " << compute_tree_height(tree.root()) << '\n';

  // Вычисление кол-во узлов в дереве (размер дерева)
  cout << "Tree size: " << compute_tree_size(tree.root()) << '\n';

  // Обход дерева в соответствии с определенной стратегией

  // 1
  InOrderTraversalStrategy in_order_strategy;

  tree.Traverse(&in_order_strategy);
  cout << "Infix (in-order) traversal\n";

  // 2
  PreOrderTraversalStrategy pre_order_strategy;

  tree.Traverse(&pre_order_strategy);
  cout << "Prefix (pre-order) traversal\n";

  // 3
  PostOrderTraversalStrategy post_order_strategy;

  tree.Traverse(&post_order_strategy);
  cout << "Postfix (post-order) traversal\n";

  // 4
  BreadthFirstTraversalStrategy bf_strategy;

  tree.Traverse(&bf_strategy);
  cout << "Breadth-first traversal\n";

  // 5
  DepthFirstTraversalStrategy df_strategy;

  tree.Traverse(&df_strategy);
  cout << "Depth-first traversal\n";

  // Преобразование двоичного дерева в массив
  auto tree_array = tree_as_array(tree.root());

  cout << "Tree as array:\n";

  for (int index = 0; index < tree_array.size(); ++index) {

    int parent_index = (index - 1) / 2;

    if (tree_array[index] == nullptr) {
      cout << '-';
    } else {
      cout << tree_array[index]->key;
    }

    if (tree_array[parent_index] != nullptr && index != 0) {
      cout << '[' << tree_array[parent_index]->key << ']';
    } else {
      cout << '[' << '-' << ']';
    }

    cout << '\t';
  }

  return 0;
}
