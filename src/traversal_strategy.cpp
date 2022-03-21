#include "classwork/traversal_strategy.hpp"

// очередь и стек из стандартной библиотеки
#include <queue>
#include <stack>

namespace classwork {

  // инфиксный обход - L(left) N(node) R(right)
  void InOrderTraversalStrategy::Print(Node* node, std::ostream& os) const {
    // Write your code here ...
  }

  // префиксный обход - N(node) L(left) R(right)
  void PreOrderTraversalStrategy::Print(Node* node, std::ostream& os) const {
    // Write your code here ...
  }

  // постфиксный обход - L(left) R(right) N(node)
  void PostOrderTraversalStrategy::Print(Node* node, std::ostream& os) const {
    // Write your code here ...
  }

  // обход в ширину - слева направо, сверху вниз
  void BreadthFirstTraversalStrategy::Print(Node* node, std::ostream& os) const {

    // Задание: внести изменения в код, чтобы обход был справа налево / сверху вниз.

    if (node == nullptr) {
      return;
    }

    // Write your code here ...
  }

  // префиксный обход (NLR) на базе стека
  void DepthFirstTraversalStrategy::Print(Node* node, std::ostream& os) const {

    if (node == nullptr) {
      return;
    }

    // Write your code here ...
  }

}  // namespace classwork