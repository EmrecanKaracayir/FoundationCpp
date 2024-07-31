#pragma once

#include "Foundation/types.hpp"

#include <exception>

namespace fn::Utility
{
  /**
   * @brief    A `noexcept` wrapper around `std::exception::what`.
   * @param    exception The exception to get the message of.
   * @return   The message of the exception.
   * @internal When MSVC decides to conform to the standard by making
   *           `std::exception::what` `noexcept`, this function will be removed.
   */
  [[nodiscard]] inline auto what(const std::exception& exception
  ) noexcept -> cstr;
} // namespace fn::Utility

/*----------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<< Implementation >>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*----------------------------------------------------------------------------*/

namespace fn::Utility
{
  [[nodiscard]] inline auto what(const std::exception& exception
  ) noexcept -> cstr
  {
#pragma warning(push)
#pragma warning(disable : 26'447)

    // Return the exception message
    return exception.what();

#pragma warning(pop)
  }
} // namespace fn::Utility

/*----------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Promotes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*----------------------------------------------------------------------------*/

// NOLINTBEGIN(misc-unused-using-decls)

namespace fn
{
  using Utility::what;
} // namespace fn

// NOLINTEND(misc-unused-using-decls)
