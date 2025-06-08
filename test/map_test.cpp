#include "map.h"

#include <glog/logging.h>
#include <gtest/gtest.h>

#include <algorithm>

TEST(MapTest, BasicTest) {
  mystl::map<std::string, int> map1 = {
      {"a", 1}, {"e", 5}, {"b", 2}, {"c", 3}, {"d", 4},
  };
  EXPECT_EQ(map1["c"], 3);
  map1["c"] = -1;
  EXPECT_EQ(map1["c"], -1);

  for (auto it = map1.begin(); it != map1.end(); it++) {
    LOG(INFO) << "key=" << it->first << " val=" << it->second << std::endl;
  }
}
