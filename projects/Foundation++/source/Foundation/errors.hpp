#pragma once

#include "Foundation/_internal/Exception/Exception.ipp"
#include "Foundation/_internal/Exception/Name.ipp"
#include "Foundation/types.hpp"

// -----------------------------< Alias Macros >----------------------------- //
#define EXCEPTION fn::_internal::Exception::Exception
#define NAME      fn::_internal::Exception::Name

// NOLINTBEGIN(bugprone-throw-keyword-missing)

namespace fn
{
  /**
   * @brief  An exception type for errors related to function or method
   *         arguments.
   * @remark Use this exception to signal that an illegal or inappropriate
   *         argument was encountered.
   */
  using ArgumentError = EXCEPTION<NAME{"ArgumentError"}, unit>;

  /**
   * @brief  An exception type for errors related to enumerators.
   * @remark Use this exception to signal that an illegal or inappropriate
   *         enumerator was encountered.
   */
  using EnumeratorError = EXCEPTION<NAME{"EnumeratorError"}, unit>;

  /**
   * @brief  An exception type for errors related to user input.
   * @remark Use this exception to signal that an illegal or inappropriate
   *         user input was encountered.
   */
  using InputError = EXCEPTION<NAME{"InputError"}, unit>;

  /**
   * @brief   An exception type for errors related to narrowing conversions.
   * @details This exception is thrown by the `fn::narrow_cast` function when
   *          the cast produces a result that cannot be accurately represented
   *          in the target type due to narrowing.
   * @warning Only use this exception in catch blocks as it is not meant to be
   *          thrown by the user.
   */
  using NarrowingError = EXCEPTION<NAME{"NarrowingError"}, unit>;
} // namespace fn

// NOLINTEND(bugprone-throw-keyword-missing)

// -----------------------------< Alias Macros >----------------------------- //
#undef EXCEPTION
#undef NAME
