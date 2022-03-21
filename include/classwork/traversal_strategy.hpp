#pragma once

#include <ostream>

#include "classwork/private/node.hpp"  // Node

namespace classwork {

  /**
   * Интерфейс обхода узлов двоичного дерева.
   */
  struct TraversalStrategy {

    virtual ~TraversalStrategy() = default;

    /**
     * Вывод ключей дерева в порядке, задаваемом стратегией обхода.
     * @param os - поток вывода
     * @param node - узел дерева (например, корневой)
     */
    virtual void Print(Node* node, std::ostream& os) const = 0;
  };

  // инфиксный обход узлов дерева
  struct InOrderTraversalStrategy final : TraversalStrategy {
    void Print(Node* node, std::ostream& os) const override;
  };

  // префиксный обход узлов дерева
  struct PreOrderTraversalStrategy final : TraversalStrategy {
    void Print(Node* node, std::ostream& os) const override;
  };

  // постфиксный обход узлов дерева
  struct PostOrderTraversalStrategy final : TraversalStrategy {
    void Print(Node* node, std::ostream& os) const override;
  };

  // level order traversal (обход в ширину)
  struct BreadthFirstTraversalStrategy final : TraversalStrategy {
    void Print(Node* node, std::ostream& os) const override;
  };

  // обход в глубину на базе стека (итеративная реализация)
  struct DepthFirstTraversalStrategy final : TraversalStrategy {
    void Print(Node* node, std::ostream& os) const override;
  };

}  // namespace classwork