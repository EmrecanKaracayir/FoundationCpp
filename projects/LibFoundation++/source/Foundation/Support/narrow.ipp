#pragma once

#include "Foundation/concepts.hpp"
#include "Foundation/errors.hpp"
#include "Foundation/types.hpp"

namespace fn::Support
{
  /**
   * @brief   Implementation of Guidelines Support Library's `narrow` function that runs on
   *          arithmetic types.
   * @param   value The value to cast.
   * @tparam  TTo The type to cast to.
   * @tparam  TFrom The type to cast from.
   * @returns The casted value.
   * @throws  NarrowingError If the value or sign changed during the cast.
   * @warning Must be preferred over static_cast for narrowing conversions.
   */
  template <IsArithmetic TTo, IsArithmetic TFrom>
  [[nodiscard]] constexpr auto narrow_cast(TFrom value) -> TTo;

  /**
   * @brief   Implementation of Guidelines Support Library's `narrow` function that runs on
   *          non-arithmetic types.
   * @param   value The value to cast.
   * @tparam  TFrom The type to cast from.
   * @tparam  TTo The type to cast to.
   * @returns The casted value.
   * @throws  NarrowingError If the value changed during the cast.
   * @warning Must be preferred over static_cast for narrowing conversions.
   */
  template <IsNotArithmetic TTo, IsNotArithmetic TFrom>
  [[nodiscard]] constexpr auto narrow_cast(TFrom value) -> TTo;
} // namespace fn::Support

/*------------------------------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Implementation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*------------------------------------------------------------------------------------------------*/

namespace fn::Support
{
#pragma warning(push)
#pragma warning(disable : 26'467 26'472)

  template <IsArithmetic TTo, IsArithmetic TFrom>
  [[nodiscard]] constexpr auto narrow_cast(TFrom value) -> TTo
  {
    // Check if signedness is different
    constexpr bln DIFFERENT_SIGNEDNESS{IsSigned<TFrom> != IsSigned<TTo>};

    // Static cast the value
    const auto castedValue{static_cast<TTo>(value)};

    // Throw error if the value changed
    if (static_cast<TFrom>(castedValue) != value)
    {
      throw NarrowingError{"Value mismatch occurred!"};
    }

    // Throw error if sign changed
    if (DIFFERENT_SIGNEDNESS and ((castedValue < TTo{}) != (value < TFrom{})))
    {
      throw NarrowingError{"Sign mismatch occurred!"};
    }

    // Return the casted value
    return castedValue;
  }

  template <IsNotArithmetic TTo, IsNotArithmetic TFrom>
  [[nodiscard]] constexpr auto narrow_cast(TFrom value) -> TTo
  {
    // Static cast the value
    const auto castedValue{static_cast<TTo>(value)};

    // Throw error if the value changed
    if (static_cast<TFrom>(castedValue) != value)
    {
      throw NarrowingError{"Value mismatch occurerd!"};
    }

    // Return the casted value
    return castedValue;
  }

#pragma warning(pop)
} // namespace fn::Support

/*------------------------------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Promotes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*------------------------------------------------------------------------------------------------*/

// NOLINTBEGIN(misc-unused-using-decls)

namespace fn
{
  using Support::narrow_cast;
} // namespace fn

// NOLINTEND(misc-unused-using-decls)
