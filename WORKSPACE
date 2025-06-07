load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# --- googletest ---
http_archive(
    name = "com_google_googletest",
    sha256 = "1f357c27ca988c3f7c6b4bf68a9395005ac6761f034046e9dde0896e3aba00e4",
    strip_prefix = "googletest-1.14.0",
    url = "https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip",
)

# --- glog ---
git_repository(
    name = "com_github_google_glog",
    remote = "https://github.com/google/glog.git",
    tag = "v0.6.0",
)

# --- gflags ---
git_repository(
    name = "com_github_gflags_gflags",
    remote = "https://github.com/gflags/gflags.git",
    tag = "v2.2.2",
)
