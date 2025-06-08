#pragma once

namespace mystl {

template <typename ValueType>
class unique_ptr {
 private:
  ValueType* data_ = nullptr;

 public:
  unique_ptr(ValueType* v);
  unique_ptr(unique_ptr&& other) noexcept;
  ~unique_ptr();

  unique_ptr() = delete;
  unique_ptr(const unique_ptr&) = delete;
  unique_ptr& operator=(const unique_ptr&) = delete;

  ValueType& operator*();
  ValueType* operator->();
};

template <typename ValueType>
unique_ptr<ValueType>::unique_ptr(ValueType* v) : data_(v) {}

template <typename ValueType>
unique_ptr<ValueType>::unique_ptr(unique_ptr&& other) noexcept
    : data_(other.data_) {
  other.data_ = nullptr;
};

template <typename ValueType>
unique_ptr<ValueType>::~unique_ptr() {
  if (data_) {
    delete data_;
  }
}

template <typename ValueType>
ValueType& unique_ptr<ValueType>::operator*() {
  return *data_;
}

template <typename ValueType>
ValueType* unique_ptr<ValueType>::operator->() {
  return data_;
}

template <typename ValueType, typename... Args>
unique_ptr<ValueType> make_unique(Args&&... args) {
  return unique_ptr(new ValueType(std::forward<Args>(args)...));
}

}  // namespace mystl
