#include "classwork/traversal_strategy.hpp"

// реализации очереди и стека из стандартной библиотеки
#include <queue>
#include <stack>

namespace classwork {

  void InOrderTraversalStrategy::Print(Node* node, std::ostream& os) const {
    if (node != nullptr) {
      Print(node->left, os);
      os << node->key << '[' << node->value << ']' << kDelimiter;
      Print(node->right, os);
    }
  }

  void PreOrderTraversalStrategy::Print(Node* node, std::ostream& os) const {
    if (node != nullptr) {
      os << node->key << '[' << node->value << ']' << kDelimiter;
      Print(node->left, os);
      Print(node->right, os);
    }
  }

  void PostOrderTraversalStrategy::Print(Node* node, std::ostream& os) const {
    if (node != nullptr) {
      Print(node->left, os);
      Print(node->right, os);
      os << node->key << '[' << node->value << ']' << kDelimiter;
    }
  }

  void BreadthFirstTraversalStrategy::Print(Node* node, std::ostream& os) const {

    if (node == nullptr) {
      return;
    }

    // кладем корневой узел в очередь
    std::queue<Node*> nodes;
    nodes.push(node);

    // пока очередь не пустая
    while (!nodes.empty()) {

      // вытаскиваем узел из очереди
      Node* curr_node = nodes.front();
      nodes.pop();

      os << curr_node->key << '[' << curr_node->value << ']' << kDelimiter;

      // кладем в очередь детей текущего узла
      if (curr_node->left != nullptr) {
        nodes.push(curr_node->left);
      }

      if (curr_node->right != nullptr) {
        nodes.push(curr_node->right);
      }
    }
  }

  void DepthFirstTraversalStrategy::Print(Node* node, std::ostream& os) const {

    if (node == nullptr) {
      return;
    }

    // кладем корневой узел на верхушку стека
    std::stack<Node*> nodes;
    nodes.push(node);

    // пока стек не пустой
    while (!nodes.empty()) {

      // вытаскиваем узел с верхушки стека
      Node* curr_node = nodes.top();
      nodes.pop();

      os << curr_node->key << '[' << curr_node->value << ']' << kDelimiter;

      // кладем в стек детей текущего узла
      if (curr_node->right != nullptr) {
        nodes.push(curr_node->right);
      }

      if (curr_node->left != nullptr) {
        nodes.push(curr_node->left);
      }
    }
  }

}  // namespace classwork