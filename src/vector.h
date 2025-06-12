#pragma once

#include <algorithm>
#include <initializer_list>
#include <stdexcept>
#include <string>

namespace mystl {

template <typename ValueType>
class vector {
 private:
  ValueType* data_;
  size_t size_;
  size_t capacity_;

 public:
  vector();
  vector(size_t size);
  vector(std::initializer_list<ValueType> init);
  vector(const vector<ValueType>& other);
  ~vector();

  size_t size() const;
  size_t capacity() const;
  ValueType* data() const;

  ValueType& operator[](size_t i);
  vector<ValueType>& operator=(vector<ValueType>& other);
  ValueType* begin();
  ValueType* end();
  const ValueType* begin() const;
  const ValueType* end() const;

  void clear();
  void push_back(ValueType v);
  void pop_back();
};

template <typename ValueType>
vector<ValueType>::vector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename ValueType>
vector<ValueType>::vector(size_t size) : size_(size), capacity_(size) {
  data_ = new ValueType[capacity_];
}

template <typename ValueType>
vector<ValueType>::vector(std::initializer_list<ValueType> init)
    : data_(nullptr), size_(init.size()), capacity_(init.size()) {
  if (size_ == 0) {
    return;
  }
  data_ = new ValueType[capacity_];
  int i = 0;
  for (const ValueType& v : init) {
    data_[i++] = v;
  }
}

template <typename ValueType>
vector<ValueType>::vector(const vector<ValueType>& other)
    : vector(other.size()) {
  std::copy(other.data(), other.data() + other.size(), data_);
}

template <typename ValueType>
vector<ValueType>::~vector() {
  delete[] data_;
}

template <typename ValueType>
size_t vector<ValueType>::size() const {
  return size_;
}

template <typename ValueType>
size_t vector<ValueType>::capacity() const {
  return capacity_;
}

template <typename ValueType>
ValueType* vector<ValueType>::data() const {
  return data_;
}

template <typename ValueType>
ValueType& vector<ValueType>::operator[](size_t i) {
  if (i >= size_) {
    throw std::out_of_range("index out of bounds");
  }
  return data_[i];
}

template <typename ValueType>
vector<ValueType>& vector<ValueType>::operator=(vector<ValueType>& other) {
  if (this == &other) {
    return *this;
  }

  delete[] data_;
  size_ = other.size();
  capacity_ = other.capacity();
  data_ = new ValueType[capacity_];
  std::copy(other.data(), other.data() + other.size(), data_);

  return *this;
}

template <typename ValueType>
ValueType* vector<ValueType>::begin() {
  return data_;
}

template <typename ValueType>
ValueType* vector<ValueType>::end() {
  return data_ + size_;
}

template <typename ValueType>
const ValueType* vector<ValueType>::begin() const {
  return data_;
}

template <typename ValueType>
const ValueType* vector<ValueType>::end() const {
  return data_ + size_;
}

template <typename ValueType>
void vector<ValueType>::clear() {
  size_ = 0;
  capacity_ = 0;
  delete[] data_;
  data_ = nullptr;
}

template <typename ValueType>
void vector<ValueType>::push_back(ValueType v) {
  if (size_ == capacity_) {
    // grow data
    capacity_ = 2 * capacity_;
    if (capacity_ < 2) {
      capacity_ = 2;
    }
    ValueType* new_data = new ValueType[capacity_];
    if (size_ > 0) {
      std::copy(data_, data_ + size_, new_data);
      delete[] data_;
    }
    data_ = new_data;
  }
  data_[size_] = v;
  size_++;
}

template <typename ValueType>
void vector<ValueType>::pop_back() {
  size_--;
}
}  // namespace mystl
