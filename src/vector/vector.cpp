#include "vector.h"

#include <iostream>

std::string mystl::version() {
  static std::string version_ = "0.0.1";
  return version_;
}
