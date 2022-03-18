#pragma once

#include "classwork/private/node.hpp"                // Node
#include "classwork/traversal_strategy.hpp"  // TraversalAlgorithm

namespace classwork {

  struct BinarySearchTree final {

    /**
     * Эквивалентно методу Clear.
     */
    ~BinarySearchTree();

    /**
     * Вставка элемента в дерево.
     *
     * В случае добавления элемента с  существующим ключом,
     * обновляется значение хранимых данных.
     *
     * @param key - значение ключа
     * @param value - хранимые данные
     */
    void Insert(int key, int value);

    /**
     * Обход дерева в соответствии со стратегией.
     *
     * @param strategy - указатель на конкретную стратегию обхода.
     */
    void Traverse(TraversalStrategy* strategy) const;

    Node* root() const;

   private:
    Node* root_{nullptr};

    // вспомогательные методы

    void insert(int key, int value, Node*& node);

    void clear(Node* node);
  };

}  // namespace classwork