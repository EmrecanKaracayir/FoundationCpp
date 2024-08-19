#pragma once

#include <concepts>
#include <ostream>
#include <type_traits>

namespace fn
{
  /**
   * @brief Concept that checks if a type is arithmetic.
   */
  template <typename T>
  concept IsArithmetic = std::is_arithmetic_v<T>;

  /**
   * @brief Concept that checks if a type is constructible from a set of arguments.
   */
  template <typename T, typename... TArgs>
  concept IsConstructible = std::constructible_from<T, TArgs...>;

  /**
   * @brief Concept that checks if a callable is invocable with a set of arguments.
   */
  template <typename TCallable, typename... TArgs>
  concept IsInvocable = std::is_invocable_v<TCallable, TArgs...>;

  /**
   * @brief Concept that checks if a type is movable.
   */
  template <typename T>
  concept IsMovable = std::movable<T>;

  /**
   * @brief Concept that checks if a type is printable.
   */
  template <typename T>
  concept IsPrintable = requires(T type, std::ostream& os) {
    { os << type } -> std::same_as<std::ostream&>;
  };

  /**
   * @brief Concept that checks if two types are the same.
   */
  template <typename TSubject, typename TCandidate>
  concept IsSame = std::same_as<TSubject, TCandidate>;

  /**
   * @brief Concept that checks if a type is signed.
   */
  template <typename T>
  concept IsSigned = std::is_signed_v<T>;

  /**
   * @brief Concept that checks if a type is unsigned.
   */
  template <typename T>
  concept IsUnsigned = std::is_unsigned_v<T>;

  /*----------------------------------------------------------------------------------------------*\
  *| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Counters >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
  \*----------------------------------------------------------------------------------------------*/

  /**
   * @brief Concept that checks if a type is non-arithmetic.
   */
  template <typename T>
  concept IsNotArithmetic = not IsArithmetic<T>;

  /**
   * @brief Concept that checks if a type is not constructible from a set of arguments.
   */
  template <typename T, typename... TArgs>
  concept IsNotConstructible = not IsConstructible<T, TArgs...>;

  /**
   * @brief Concept that checks if a callable is not invocable with a set of arguments.
   */
  template <typename TCallable, typename... TArgs>
  concept IsNotInvocable = not IsInvocable<TCallable, TArgs...>;

  /**
   * @brief Concept that checks if a type is not movable.
   */
  template <typename T>
  concept IsNotMovable = not IsMovable<T>;

  /**
   * @brief Concept that checks if a type is not printable.
   */
  template <typename T>
  concept IsNotPrintable = not IsPrintable<T>;

  /**
   * @brief Concept that checks if two types are not the same.
   */
  template <typename TSubject, typename TCandidate>
  concept IsNotSame = not IsSame<TSubject, TCandidate>;

  /**
   * @brief Concept that checks if a type is not signed.
   */
  template <typename T>
  concept IsNotSigned = not IsSigned<T>;

  /**
   * @brief Concept that checks if a type is not unsigned.
   */
  template <typename T>
  concept IsNotUnsigned = not IsUnsigned<T>;
} // namespace fn
