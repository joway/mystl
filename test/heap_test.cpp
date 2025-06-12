#include "heap.h"

#include <gtest/gtest.h>

#include <iostream>

#include "vector.h"

TEST(HeapTest, MakeHeapTest) {
  mystl::greater greater_than;
  mystl::vector<int> vec1{3, 2, 4, 6, 5, 7, 1, 8};
  mystl::make_heap(vec1.begin(), vec1.end(), greater_than);
  for (int i = vec1.size(); i > 0; i--) {
    mystl::pop_heap(vec1.begin(), vec1.end(), greater_than);
    EXPECT_EQ(vec1[vec1.size() - 1], i);
    vec1.pop_back();
  }

  mystl::less less_than;
  mystl::vector<int> vec2{3, 2, 4, 6, 5, 7, 1, 8};
  mystl::make_heap(vec2.begin(), vec2.end(), less_than);
  for (int i = 1; i <= vec2.size(); i++) {
    mystl::pop_heap(vec2.begin(), vec2.end(), less_than);
    EXPECT_EQ(vec2[vec2.size() - 1], i);
    vec2.pop_back();
  }
}

TEST(HeapTest, MaxHeapTest) {
  mystl::greater comp;

  mystl::vector<int> vec1{};
  vec1.push_back(2);
  mystl::push_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[0], 2);
  vec1.push_back(3);
  mystl::push_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[0], 3);
  vec1.push_back(1);
  mystl::push_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[0], 3);

  mystl::pop_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[vec1.size() - 1], 3);
  vec1.pop_back();
  mystl::pop_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[vec1.size() - 1], 2);
  vec1.pop_back();
  mystl::pop_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[vec1.size() - 1], 1);
  vec1.pop_back();
}

TEST(HeapTest, MinHeapTest) {
  mystl::less comp;

  mystl::vector<int> vec1{};
  vec1.push_back(2);
  mystl::push_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[0], 2);
  vec1.push_back(3);
  mystl::push_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[0], 2);
  vec1.push_back(1);
  mystl::push_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[0], 1);

  mystl::pop_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[vec1.size() - 1], 1);
  vec1.pop_back();
  mystl::pop_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[vec1.size() - 1], 2);
  vec1.pop_back();
  mystl::pop_heap(vec1.begin(), vec1.end(), comp);
  EXPECT_EQ(vec1[vec1.size() - 1], 3);
  vec1.pop_back();
}
