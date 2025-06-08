#pragma once

#include "list.h"

namespace mystl {

template <typename ValueType>
class stack {
 private:
  list<ValueType> data_;

 public:
  stack() = default;
  ~stack() = default;

  size_t size();
  void push(const ValueType& v);
  void pop();
  ValueType& top();
};

template <typename ValueType>
size_t stack<ValueType>::size() {
  return data_.size();
}

template <typename ValueType>
void stack<ValueType>::push(const ValueType& v) {
  data_.push_back(v);
}

template <typename ValueType>
void stack<ValueType>::pop() {
  data_.pop_back();
}

template <typename ValueType>
ValueType& stack<ValueType>::top() {
  return data_.back();
}

}  // namespace mystl
