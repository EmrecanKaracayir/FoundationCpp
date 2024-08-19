#pragma once

#include "Foundation/types.hpp"

#include <algorithm>
#include <span>

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)

namespace fn::_internal::Exception
{
  /**
   * @brief  A fixed-length string that represents the name of an exception.
   * @tparam length The length of the name.
   */
  template <size length>
  struct Name
  {
    /*-----------------------------------------------------------------------------------+--------*\
    *| [public]: Constructors                                                            | PUBLIC |*
    \*-----------------------------------------------------------------------------------+--------*/

    /**
     * @brief Constructs a name from a C-style string.
     * @param name The C-style string.
     */
    consteval explicit Name(const cdef (&name)[length]) noexcept;

    /*-----------------------------------------------------------------------------------+--------*\
    *| [public]: Fields                                                                  | PUBLIC |*
    \*-----------------------------------------------------------------------------------+--------*/

    cdef value[length]{};
  };
} // namespace fn::_internal::Exception

/*------------------------------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Deduction Guides >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*------------------------------------------------------------------------------------------------*/

namespace fn::_internal::Exception
{
  template <size length>
  Name(const cdef (&)[length]) -> Name<length>;
} // namespace fn::_internal::Exception

/*------------------------------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Implementation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*------------------------------------------------------------------------------------------------*/

namespace fn::_internal::Exception
{
  /*-------------------------------------------------------------------------------------+--------*\
  *| [public]: Constructors                                                              | PUBLIC |*
  \*-------------------------------------------------------------------------------------+--------*/

  template <size length>
  consteval Name<length>::Name(const cdef (&name)[length]) noexcept
  {
    // Copy the name
    std::ranges::copy_n(static_cast<const cdef*>(name), length, std::span<cdef>{value}.begin());
  }
} // namespace fn::_internal::Exception

// NOLINTEND(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)
