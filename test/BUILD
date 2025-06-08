gmain_src = ["main_test.cpp"]

common_deps = [
    "@com_github_google_glog//:glog",
    "@com_google_googletest//:gtest_main",
]

cc_test(
    name = "vector_test",
    srcs = ["vector_test.cpp"] + gmain_src,
    deps = [
        "//src:vector",
    ] + common_deps,
)

cc_test(
    name = "map_test",
    srcs = ["map_test.cpp"] + gmain_src,
    deps = [
        "//src:map",
    ] + common_deps,
)

cc_test(
    name = "list_test",
    srcs = ["list_test.cpp"] + gmain_src,
    deps = [
        "//src:list",
    ] + common_deps,
)

cc_test(
    name = "stack_test",
    srcs = ["stack_test.cpp"] + gmain_src,
    deps = [
        "//src:stack",
    ] + common_deps,
)
