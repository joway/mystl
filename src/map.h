#pragma once

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>

#include "list.h"

namespace mystl {

template <typename KeyType, typename ValueType>
class map {
 private:
  struct node {
    KeyType key;
    ValueType val;
    node* parent;
    node* left;
    node* right;

    node(KeyType k, ValueType v)
        : key(k), val(v), parent(nullptr), left(nullptr), right(nullptr) {}
  };

  node* data_;
  size_t size_;

 public:
  class iterator {
   private:
    node* node_;
    std::pair<KeyType, ValueType> pair_;

   public:
    iterator(node* n);
    iterator& operator++();    // ++it
    iterator operator++(int);  // it++
    std::pair<KeyType, ValueType>& operator*();
    std::pair<KeyType, ValueType>* operator->();
    bool operator!=(const iterator& other);
    bool operator==(const iterator& other);
  };

  map();
  map(std::initializer_list<std::pair<const KeyType, ValueType>> init);
  ~map();

  ValueType& operator[](const KeyType& k);
  size_t size();
  bool empty();
  void insert(const KeyType& k, const ValueType& v);

  iterator begin();
  iterator end();

 private:
  void destroy_node(node* n);
  node* get_or_create_node(const KeyType& k);
};

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::map() : data_(nullptr), size_(0) {}

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::map(
    std::initializer_list<std::pair<const KeyType, ValueType>> init)
    : map() {
  for (const auto& p : init) {
    insert(p.first, p.second);
  }
}

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::~map() {
  destroy_node(data_);
}

template <typename KeyType, typename ValueType>
ValueType& map<KeyType, ValueType>::operator[](const KeyType& k) {
  node* found = get_or_create_node(k);
  return found->val;
}

template <typename KeyType, typename ValueType>
size_t map<KeyType, ValueType>::size() {
  return size_;
}

template <typename KeyType, typename ValueType>
bool map<KeyType, ValueType>::empty() {
  return size_ == 0;
}

template <typename KeyType, typename ValueType>
void map<KeyType, ValueType>::insert(const KeyType& k, const ValueType& v) {
  node* n = get_or_create_node(k);
  n->val = v;
  return;
}

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::iterator map<KeyType, ValueType>::begin() {
  // find leftest node
  node* n = data_;
  while (n != nullptr && n->left != nullptr) {
    n = n->left;
  }
  return iterator(n);
}

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::iterator map<KeyType, ValueType>::end() {
  return map<KeyType, ValueType>::iterator(nullptr);
}

template <typename KeyType, typename ValueType>
void map<KeyType, ValueType>::destroy_node(node* n) {
  if (n == nullptr) return;
  destroy_node(n->left);
  destroy_node(n->right);
  delete n;
}

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::node* map<KeyType, ValueType>::get_or_create_node(
    const KeyType& k) {
  if (data_ == nullptr) {
    data_ = new node(k, ValueType{});
    size_++;
    return data_;
  }
  node* parent = nullptr;
  for (node* cur = data_; cur != nullptr;) {
    if (k == cur->key) {
      return cur;
    } else if (k < cur->key) {
      parent = cur;
      cur = cur->left;
    } else {
      parent = cur;
      cur = cur->right;
    }
  }
  size_++;
  node* new_node = new node(k, ValueType{});
  new_node->parent = parent;
  if (k < parent->key) {
    parent->left = new_node;
  } else {
    parent->right = new_node;
  }
  return new_node;
}

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::iterator::iterator(node* n) : node_(n) {
  if (n == nullptr) {
    return;
  }
  pair_.first = node_->key;
  pair_.second = node_->val;
  //   pair_ = std::make_pair(node_->key, node_->val);
}

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::iterator&
map<KeyType, ValueType>::iterator::operator++() {
  node* n = node_;
  if (n == nullptr) {
    return *this;
  }
  if (n->right != nullptr) {
    // have right node, find the leftest node
    n = n->right;
    while (n->left != nullptr) {
      n = n->left;
    }
  } else {
    // backtrace parent nodes until find the right side tree
    node* bt_node = n->parent;
    while (bt_node != nullptr && n != bt_node->left) {
      n = bt_node;
      bt_node = bt_node->parent;
    }
    n = bt_node;
  }
  node_ = n;
  if (node_) {
    pair_.first = node_->key;
    pair_.second = node_->val;
  }
  return *this;
}

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::iterator map<KeyType, ValueType>::iterator::operator++(
    int) {
  iterator tmp = *this;
  ++(*this);
  return tmp;
}

template <typename KeyType, typename ValueType>
std::pair<KeyType, ValueType>& map<KeyType, ValueType>::iterator::operator*() {
  return pair_;
}

template <typename KeyType, typename ValueType>
std::pair<KeyType, ValueType>* map<KeyType, ValueType>::iterator::operator->() {
  return &pair_;
}

template <typename KeyType, typename ValueType>
bool map<KeyType, ValueType>::iterator::operator!=(const iterator& other) {
  return node_ != other.node_;
}

template <typename KeyType, typename ValueType>
bool map<KeyType, ValueType>::iterator::operator==(const iterator& other) {
  return node_ == other.node_;
}
}  // namespace mystl