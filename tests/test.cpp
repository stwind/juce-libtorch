#include <catch2/catch_test_macros.hpp>
#include <torch/torch.h>
#include <cstdint>

TEST_CASE("libtorch", "[tensor]") {
  torch::Tensor x = torch::arange(10);
  REQUIRE(x[3].allclose(torch::tensor(3)));
}