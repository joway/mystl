#pragma once

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace mystl {

template <typename ValueType>
class list {
 private:
  struct node {
    ValueType val;
    node* prev;
    node* next;
    node() : node(ValueType{}) {};
    node(ValueType v) : val(v), prev(nullptr), next(nullptr) {};
  };
  node* head_;
  node* tail_;
  size_t size_;

  void insert_node_before(const ValueType& v, node* next_node);
  void delete_node(node* target_node);

 public:
  list();
  list(std::initializer_list<ValueType> init);
  ~list();

  size_t size();
  void push_front(const ValueType& v);
  void push_back(const ValueType& v);
  ValueType& front();
  ValueType& back();
  void pop_front();
  void pop_back();
};

template <typename ValueType>
list<ValueType>::list() : size_(0) {
  head_ = new node(0);
  tail_ = new node(0);
  head_->prev = tail_;
  head_->next = tail_;
  tail_->prev = head_;
  tail_->next = head_;
}

template <typename ValueType>
list<ValueType>::list(std::initializer_list<ValueType> init) : list() {
  for (auto& i : init) {
    this->push_back(i);
  }
}

template <typename ValueType>
list<ValueType>::~list() {
  node* cur = head_->next;
  while (cur != tail_) {
    node* next = cur->next;
    delete cur;
    cur = next;
  }
  delete head_;
  delete tail_;
  head_ = nullptr;
  tail_ = nullptr;
}

template <typename ValueType>
size_t list<ValueType>::size() {
  return size_;
}

template <typename ValueType>
void list<ValueType>::push_front(const ValueType& v) {
  insert_node_before(v, head_->next);
}

template <typename ValueType>
void list<ValueType>::push_back(const ValueType& v) {
  insert_node_before(v, tail_);
}

template <typename ValueType>
ValueType& list<ValueType>::front() {
  if (size_ == 0) {
    throw std::out_of_range("empty list");
  }
  return head_->next->val;
}

template <typename ValueType>
ValueType& list<ValueType>::back() {
  if (size_ == 0) {
    throw std::out_of_range("empty list");
  }
  return tail_->prev->val;
}

template <typename ValueType>
void list<ValueType>::pop_front() {
  if (size_ == 0) {
    return;
  }
  delete_node(head_->next);
}

template <typename ValueType>
void list<ValueType>::pop_back() {
  if (size_ == 0) {
    return;
  }
  delete_node(tail_->prev);
}

template <typename ValueType>
void list<ValueType>::insert_node_before(const ValueType& v, node* next_node) {
  size_++;
  node* target_node = new node(v);
  node* prev_node = next_node->prev;
  prev_node->next = target_node;
  target_node->prev = prev_node;
  target_node->next = next_node;
  next_node->prev = target_node;
}

template <typename ValueType>
void list<ValueType>::delete_node(node* target_node) {
  size_--;
  node* prev_node = target_node->prev;
  node* next_node = target_node->next;
  prev_node->next = next_node;
  next_node->prev = prev_node;
  delete target_node;
}

}  // namespace mystl