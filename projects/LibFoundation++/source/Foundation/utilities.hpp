#pragma once

#include "Foundation/types.hpp"

#include <bitset>
#include <optional>
#include <utility>

namespace fn
{
  /**
   * @brief  A type that represents an optional value.
   * @tparam T The type of the value that may or may not be present.
   */
  template <typename T>
  using opt = std::optional<T>;

  /**
   * @brief  A type that represents a pair of values.
   * @tparam TFirst The type of the first value.
   * @tparam TSecond The type of the second value.
   */
  template <typename TFirst, typename TSecond>
  using pair = std::pair<TFirst, TSecond>;

  /**
   * @brief  A type that represents a bitset.
   * @tparam bitCount The number of bits in the bitset.
   */
  template <size bitCount>
  using bitset = std::bitset<bitCount>;
} // namespace fn
