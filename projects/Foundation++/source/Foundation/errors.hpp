#pragma once

#include "Foundation/_internal/Exception/Exception.ipp"
#include "Foundation/_internal/Exception/Name.ipp"
#include "Foundation/types.hpp"

// ---------------------------------------< Alias Macros >--------------------------------------- //
#if not defined(EXCEPTION) and not defined(NAME)
  #define EXCEPTION fn::_internal::Exception::Exception
  #define NAME      fn::_internal::Exception::Name

// NOLINTBEGIN(bugprone-throw-keyword-missing)

namespace fn
{
  /**
   * @brief  An exception type for errors related to function or method arguments.
   * @remark Use this exception to signal that an illegal or inappropriate argument was encountered.
   */
  using ArgumentError = EXCEPTION<NAME{"ArgumentError"}, str>;

  /**
   * @brief  An exception type for errors related to enumerators.
   * @remark Use this exception to signal that an illegal or inappropriate enumerator was
   *         encountered.
   */
  using EnumeratorError = EXCEPTION<NAME{"EnumeratorError"}, str>;

  /**
   * @brief  An exception type for errors related to file operations.
   * @remark Use this exception to signal that an illegal or inappropriate file operation was
   *         encountered.
   */
  using FileError = EXCEPTION<NAME{"FileError"}, str>;

  /**
   * @brief  An exception type for errors related to user input.
   * @remark Use this exception to signal that an illegal or inappropriate user input was
   *         encountered.
   */
  using InputError = EXCEPTION<NAME{"InputError"}, str>;

  /**
   * @brief   An exception type for errors related to narrowing conversions.
   * @details This exception is thrown by the `fn::narrow_cast` function when the cast produces a
   *          result that cannot be accurately represented in the target type due to narrowing.
   * @warning Only use this exception in catch blocks as it is not meant to be thrown by the user.
   */
  using NarrowingError = EXCEPTION<NAME{"NarrowingError"}, str>;

  /**
   * @brief  An exception type for errors related to states.
   * @remark Use this exception to signal that an illegal or inappropriate state was encountered.
   */
  using StateError = EXCEPTION<NAME{"StateError"}, str>;

  /**
   * @brief  An exception type for errors related to types.
   * @remark Use this exception to signal that an illegal or inappropriate type was encountered.
   */
  using TypeError = EXCEPTION<NAME{"TypeError"}, str>;
} // namespace fn

// NOLINTEND(bugprone-throw-keyword-missing)

  #undef EXCEPTION
  #undef NAME
#endif
