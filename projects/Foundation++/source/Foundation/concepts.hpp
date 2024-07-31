#pragma once

#include <concepts>
#include <ostream>
#include <type_traits>

namespace fn
{
  /**
   * @brief Concept that checks if a type is arithmetic.
   */
  template <typename Type>
  concept IsArithmetic = std::is_arithmetic_v<Type>;

  /**
   * @brief Concept that checks if a type is constructible from a set of
   *        arguments.
   */
  template <typename Type, typename... Args>
  concept IsConstructible = std::constructible_from<Type, Args...>;

  /**
   * @brief Concept that checks if a callable is invocable with a set of
   *        arguments.
   */
  template <typename Callable, typename... Args>
  concept IsInvocable = std::is_invocable_v<Callable, Args...>;

  /**
   * @brief Concept that checks if a type is movable.
   */
  template <typename Type>
  concept IsMovable = std::movable<Type>;

  /**
   * @brief Concept that checks if a type is printable.
   */
  template <typename Type>
  concept IsPrintable = requires(Type type, std::ostream& os) {
    { os << type } -> std::same_as<std::ostream&>;
  };

  /**
   * @brief Concept that checks if a type is signed.
   */
  template <typename Type>
  concept IsSigned = std::is_signed_v<Type>;

  /**
   * @brief Concept that checks if a type is unsigned.
   */
  template <typename Type>
  concept IsUnsigned = std::is_unsigned_v<Type>;

  /*--------------------------------------------------------------------------*\
  *| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Counters >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
  \*--------------------------------------------------------------------------*/

  /**
   * @brief Concept that checks if a type is non-arithmetic.
   */
  template <typename Type>
  concept IsNotArithmetic = not IsArithmetic<Type>;

  /**
   * @brief Concept that checks if a type is not constructible from a set of
   *        arguments.
   */
  template <typename Type, typename... Args>
  concept IsNotConstructible = not IsConstructible<Type, Args...>;

  /**
   * @brief Concept that checks if a callable is not invocable with a set of
   *        arguments.
   */
  template <typename Callable, typename... Args>
  concept IsNotInvocable = not IsInvocable<Callable, Args...>;

  /**
   * @brief Concept that checks if a type is not movable.
   */
  template <typename Type>
  concept IsNotMovable = not IsMovable<Type>;

  /**
   * @brief Concept that checks if a type is not printable.
   */
  template <typename Type>
  concept IsNotPrintable = not IsPrintable<Type>;

  /**
   * @brief Concept that checks if a type is not signed.
   */
  template <typename Type>
  concept IsNotSigned = not IsSigned<Type>;

  /**
   * @brief Concept that checks if a type is not unsigned.
   */
  template <typename Type>
  concept IsNotUnsigned = not IsUnsigned<Type>;
} // namespace fn
