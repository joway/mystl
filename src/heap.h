#pragma once

#include <algorithm>
#include <iostream>

namespace mystl {

class greater {
 public:
  template <typename T, typename U>
  bool operator()(const T& a, const U& b) const {
    return a > b;
  }
};

class less {
 public:
  template <typename T, typename U>
  bool operator()(const T& a, const U& b) const {
    return a < b;
  }
};

template <typename It, typename Compare>
void heap_sift_up(It start, It end, Compare comp) {
  int size = end - start;
  // sift up until comp() return false
  for (int current_idx = size - 1; current_idx != 0;) {
    int parent_idx = (current_idx - 1) / 2;
    It current = start + current_idx;
    It parent = start + parent_idx;
    if (!comp(*current, *parent)) {
      break;
    }
    std::iter_swap(current, parent);
    current_idx = parent_idx;
  }
}

template <typename It, typename Compare>
void heap_sift_down(It start, It end, Compare comp) {
  int size = end - start;
  int current_idx = 0;
  // sift down left/right side until comp() return true
  while (current_idx <= size - 1) {
    int left_child_idx = current_idx * 2 + 1;
    int right_child_idx = current_idx * 2 + 2;
    if (left_child_idx >= size) {
      break;
    }
    It left_child = (start + left_child_idx);
    It right_child = (start + right_child_idx);
    It current = (start + current_idx);

    // comp_best(left_child, right_child): max/min of two sides
    // if comp == greater, choice max(left_child, right_child)
    It best = left_child;
    int best_idx = left_child_idx;
    if (right_child_idx < size && comp(*right_child, *left_child)) {
      best = right_child;
      best_idx = right_child_idx;
    }
    if (comp(*current, *best)) {
      break;
    }
    std::iter_swap(current, best);
    current_idx = best_idx;
  }
}

template <typename It, typename Compare>
void make_heap(It start, It end, Compare comp) {
  int size = end - start;
  if (size <= 1) return;
  for (int i = 1; i <= size; i++) {
    // shift up
    push_heap(start, start + i, comp);
  }
}

template <typename It, typename Compare>
void push_heap(It start, It end, Compare comp) {
  heap_sift_up(start, end, comp);
}

template <typename It, typename Compare>
void pop_heap(It start, It end, Compare comp) {
  It last = start + (end - start) - 1;
  std::iter_swap(start, last);
  heap_sift_down(start, last, comp);
}
}  // namespace mystl