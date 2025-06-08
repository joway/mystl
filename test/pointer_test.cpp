#include <glog/logging.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <string>

#include "unique_ptr.h"

struct User {
  std::string username;
  User(std::string name) : username(name) {}
};

TEST(UniquePtrTest, BasicTest) {
  std::string username = "joway";
  mystl::unique_ptr<User> ptr1 = mystl::make_unique<User>(username);
  EXPECT_EQ((*ptr1).username, username);
  EXPECT_EQ(ptr1->username, username);

  // mystl::unique_ptr<User> ptr2 = ptr1;
  mystl::unique_ptr<User> ptr2 = std::move(ptr1);
  EXPECT_EQ((*ptr1).username, username);
  EXPECT_EQ(ptr1->username, username);
}
