#include <glog/logging.h>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  google::InitGoogleLogging(argv[0]);  // 初始化 glog

  // 设置 glog 行为（可选但推荐）
  FLAGS_logtostderr = 1;  // 把日志输出到 stderr（控制台）

  return RUN_ALL_TESTS();
}
