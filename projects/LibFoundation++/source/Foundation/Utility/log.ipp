#pragma once

#include "Foundation/concepts.hpp"
#include "Foundation/types.hpp"

#include <cassert>
#include <iostream>

namespace fn::Utility
{
  /**
   * @brief    A `noexcept` wrapper around `std::cerr`.
   * @param    message The message to log.
   * @tparam   T The type of the message.
   * @note     Inserts a newline character after the message.
   * @internal A proper logging library will surpass this function.
   */
  template <IsPrintable T>
  auto elog(const T& message) noexcept -> none;
} // namespace fn::Utility

/*------------------------------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Implementation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*------------------------------------------------------------------------------------------------*/

namespace fn::Utility
{
  // NOLINTBEGIN(bugprone-exception-escape)

  template <IsPrintable T>
  auto elog(const T& message) noexcept -> none
  {
    // Ensure that the stream is in a non-throwing state
    assert(std::cout.exceptions() == std::ios_base::iostate{0});

#pragma warning(push)
#pragma warning(disable : 26'447)

    // NOLINTBEGIN(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)

    // Log the exception
    std::cerr << '\n' << message << '\n';

    // NOLINTEND(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)

#pragma warning(pop)
  }

  // NOLINTEND(bugprone-exception-escape)
} // namespace fn::Utility

/*------------------------------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Promotes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*------------------------------------------------------------------------------------------------*/

// NOLINTBEGIN(misc-unused-using-decls)

namespace fn
{
  using Utility::elog;
} // namespace fn

// NOLINTEND(misc-unused-using-decls)
