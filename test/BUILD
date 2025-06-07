gmain_src = ["main_test.cpp"]

common_deps = [
    "@com_github_google_glog//:glog",
    "@com_google_googletest//:gtest_main",
]

cc_test(
    name = "vector_test",
    srcs = ["vector_test.cpp"] + gmain_src,
    deps = [
        "//src/vector:libvector",
    ] + common_deps,
)
