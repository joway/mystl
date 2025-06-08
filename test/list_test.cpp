#include "list.h"

#include <glog/logging.h>
#include <gtest/gtest.h>

#include <algorithm>

TEST(ListTest, BasicTest) {
  mystl::list<int> list1 = {1, 2, 3};
  EXPECT_EQ(list1.size(), 3);
  EXPECT_EQ(list1.front(), 1);
  EXPECT_EQ(list1.back(), 3);
  list1.pop_front();
  EXPECT_EQ(list1.size(), 2);
  EXPECT_EQ(list1.front(), 2);
  list1.pop_back();
  EXPECT_EQ(list1.size(), 1);
  EXPECT_EQ(list1.back(), 2);
}
