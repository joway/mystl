#pragma once

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>

namespace mystl {

template <typename KeyType, typename ValueType>
class map {
 private:
  struct node {
    KeyType key;
    ValueType val;
    node* left;
    node* right;

    node(KeyType k, ValueType v)
        : key(k), val(v), left(nullptr), right(nullptr) {}
  };

  node* data_;
  size_t size_;

 public:
  map();
  map(std::initializer_list<std::pair<const KeyType, ValueType>> init);
  ~map();

  ValueType& operator[](const KeyType& k);

  void insert(const KeyType& k, const ValueType& v);

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
void map<KeyType, ValueType>::insert(const KeyType& k, const ValueType& v) {
  node* n = get_or_create_node(k);
  n->val = v;
  return;
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
  if (k < parent->key) {
    parent->left = new node(k, ValueType{});
    return parent->left;
  }
  parent->right = new node(k, ValueType{});
  return parent->right;
}
}  // namespace mystl