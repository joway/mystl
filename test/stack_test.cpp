#include "stack.h"

#include <glog/logging.h>
#include <gtest/gtest.h>

#include <algorithm>

TEST(StackTest, BasicTest) {
  mystl::stack<int> stack1;
  stack1.push(1);
  stack1.push(2);
  stack1.push(3);
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 3);
  stack1.pop();
  EXPECT_EQ(stack1.top(), 2);
  EXPECT_EQ(stack1.size(), 2);
}
