#pragma once

#include <optional>
#include <utility>

namespace fn
{
  /**
   * @brief  A type that represents an optional value.
   * @tparam Type The type of the value that may or may not be present.
   */
  template <typename Type>
  using opt = std::optional<Type>;

  /**
   * @brief  A type that represents a pair of values.
   * @tparam FirstType The type of the first value.
   * @tparam SecondType The type of the second value.
   */
  template <typename FirstType, typename SecondType>
  using pair = std::pair<FirstType, SecondType>;
} // namespace fn
