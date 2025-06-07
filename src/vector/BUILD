load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "libvector",
    srcs = ["vector.cpp"],
    hdrs = ["vector.h"],
    include_prefix = "vector",  # 加上虚拟的 vector/ 作为头文件可用路径
    strip_include_prefix = ".",  # 去掉路径前缀 src/vector/
    visibility = ["//visibility:public"],
)
