unit=$1
bazel test --test_output=all --sandbox_debug --verbose_failures //test:$unit
