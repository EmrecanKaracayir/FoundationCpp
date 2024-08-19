#pragma once

#include "Foundation/types.hpp"

#include <cstdlib>
#include <optional>

namespace fn
{
  /**
   * @brief The exit code for successful termination of a program.
   */
  inline constexpr idef EXIT_SUCCESS_CODE{EXIT_SUCCESS};

  /**
   * @brief The exit code for unsuccessful termination of a program.
   */
  inline constexpr idef EXIT_FAILURE_CODE{EXIT_FAILURE};

  /**
   * @brief  Exception identifier for unknown exceptions.
   * @remark Use in catch-all blocks to identify unknown exceptions.
   */
  inline constexpr strv UNKNOWN_EXCEPTION{"Unknown exception"};

  /**
   * @brief   A constant indicating an `fn::opt` does not contain a value.
   * @warning Use this instead of `{}` to avoid ambiguity.
   */
  inline constexpr std::nullopt_t nopt{std::nullopt};
} // namespace fn
