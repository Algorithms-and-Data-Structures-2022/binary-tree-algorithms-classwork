#include <iostream>  // cout

#include "classwork/binary_search_tree.hpp"  // BinarySearchTree

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

  return 0;
}
