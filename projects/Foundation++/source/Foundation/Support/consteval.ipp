#pragma once

#include "Foundation/concepts.hpp"

#include <functional>
#include <utility>

namespace fn::Support
{
  /**
   * @brief   Forces the compiler to evaluate the expression at compile-time.
   * @details This function is marked as `consteval`, which ensures that it is always evaluated at
   *          compile-time. It effectively returns the provided value, but the evaluation is
   *          enforced to occur during compilation.
   * @param   value The value to be evaluated and returned.
   * @returns The value passed in.
   */
  [[nodiscard]] consteval auto as_consteval(auto value) noexcept -> auto;

  /**
   * @brief   Constructs an object of type `Type` with the given arguments at compile-time.
   * @details This function template is `consteval` and requires that `Type` is constructible from
   *          the provided arguments. It forces the construction of the object to occur at
   *          compile-time.
   * @tparam  Type The type of the object to construct.
   * @tparam  Args The types of the arguments used to construct the object.
   * @param   args Arguments to pass to the constructor of `Type`.
   * @returns An object of type `Type` constructed with the provided arguments.
   */
  template <typename Type, typename... Args>
  requires IsConstructible<Type, Args...>
  [[nodiscard]] consteval auto make_consteval(Args&&... args) -> Type;

  /**
   * @brief   Invokes a callable object with the given arguments at compile-time.
   * @details This function template is `consteval` and requires that the callable can be invoked
   *          with the provided arguments. It forces compile-time evaluation by invoking the
   *          callable and returning the result.
   * @tparam  callable The callable object to be invoked.
   * @tparam  Args The types of the arguments to pass to the callable.
   * @param   args Arguments to pass to the callable.
   * @returns The result of invoking the callable with the provided arguments.
   */
  template <auto callable, typename... Args>
  requires IsInvocable<decltype(callable), Args...>
  [[nodiscard]] consteval auto make_consteval(Args&&... args) -> auto;
} // namespace fn::Support

/*------------------------------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Implementation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*------------------------------------------------------------------------------------------------*/

namespace fn::Support
{
  [[nodiscard]] consteval auto as_consteval(auto value) noexcept -> auto
  {
    // Return the value
    return value;
  }

  template <typename Type, typename... Args>
  requires IsConstructible<Type, Args...>
  [[nodiscard]] consteval auto make_consteval(Args&&... args) -> Type
  {
    // Construct the type and return it
    return Type{std::forward<Args>(args)...};
  }

  template <auto callable, typename... Args>
  requires IsInvocable<decltype(callable), Args...>
  [[nodiscard]] consteval auto make_consteval(Args&&... args) -> auto
  {
    // Invoke the callable and return the result
    return std::invoke(callable, std::forward<Args>(args)...);
  }
} // namespace fn::Support

/*------------------------------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Promotes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*------------------------------------------------------------------------------------------------*/

// NOLINTBEGIN(misc-unused-using-decls)

namespace fn
{
  using Support::as_consteval;
  using Support::make_consteval;
} // namespace fn

// NOLINTEND(misc-unused-using-decls)
