#include "vector.h"

#include <glog/logging.h>
#include <gtest/gtest.h>

#include <algorithm>

TEST(VectorTest, BasicTest) {
  mystl::vector<int> vec1(3);
  EXPECT_EQ(vec1.size(), 3);
  vec1[0] = 1;
  vec1[1] = 2;
  vec1[2] = 3;
  for (int i = 1; i <= 3; i++) {
    EXPECT_EQ(vec1[i - 1], i);
  }
  vec1.clear();
  EXPECT_EQ(vec1.size(), 0);

  vec1.push_back(1);
  vec1.push_back(2);
  vec1.push_back(3);
  EXPECT_EQ(vec1.size(), 3);
  for (int i = 1; i <= 3; i++) {
    EXPECT_EQ(vec1[i - 1], i);
  }

  mystl::vector vec2 = {1, 2, 3};
  EXPECT_EQ(vec2.size(), 3);
  for (int i = 1; i <= 3; i++) {
    EXPECT_EQ(vec2[i - 1], i);
  }
  auto it = std::find(vec2.begin(), vec2.end(), 2);
  EXPECT_EQ(*it, 2);

  mystl::vector vec3 = vec2;
  EXPECT_EQ(vec2.size(), 3);
  for (int i = 1; i <= 3; i++) {
    EXPECT_EQ(vec2[i - 1], i);
  }

  vec1 = vec3;
  EXPECT_EQ(vec1.size(), 3);
  for (int i = 1; i <= 3; i++) {
    EXPECT_EQ(vec1[i - 1], i);
  }

  mystl::vector<int> vec4 = std::move(vec1);
  EXPECT_EQ(vec4.size(), 3);
  for (int i = 1; i <= 3; i++) {
    EXPECT_EQ(vec4[i - 1], i);
  }
  int v = 1;
  for (int& i : vec4) {
    EXPECT_EQ(i, v);
    v++;
  }
}
