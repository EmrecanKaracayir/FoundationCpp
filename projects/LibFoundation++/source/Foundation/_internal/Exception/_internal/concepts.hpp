#pragma once

#include "Foundation/concepts.hpp"

#include "Foundation/types.hpp"

namespace fn::_internal::Exception::_internal
{
  /**
   * @brief Concept to check if a type can be a Context.
   */
  template <typename T>
  concept IsContext = IsSameAs<unit, T> or (IsMovable<T> and IsPrintable<T>);
} // namespace fn::_internal::Exception::_internal
