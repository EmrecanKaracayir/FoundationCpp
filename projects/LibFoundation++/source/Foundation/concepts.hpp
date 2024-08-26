#pragma once

#include <concepts>
#include <ostream>
#include <type_traits>

namespace fn
{
  /**
   * @brief  Concept that checks if all subject types are the same as the candidate type.
   * @remark "The subjects `AreSameAs` the candidate."
   */
  template <typename TCandidate, typename... TSubjects>
  concept AreSameAs = (std::same_as<TCandidate, TSubjects> and ...);

  /**
   * @brief  Concept that checks if a type is arithmetic.
   * @remark "The type `IsArithmetic`."
   */
  template <typename T>
  concept IsArithmetic = std::is_arithmetic_v<T>;

  /**
   * @brief  Concept that checks if a type is constructible from a set of arguments.
   * @remark "The type `IsConstructibleFrom` the arguments."
   */
  template <typename T, typename... TArguments>
  concept IsConstructibleFrom = std::constructible_from<T, TArguments...>;

  /**
   * @brief  Concept that checks if a callable is invocable with a set of arguments.
   * @remark "The callable `IsInvocableWith` the arguments."
   */
  template <typename TCallable, typename... TArguments>
  concept IsInvocableWith = std::is_invocable_v<TCallable, TArguments...>;

  /**
   * @brief  Concept that checks if a type is movable.
   * @remark "The type `IsMovable`."
   */
  template <typename T>
  concept IsMovable = std::movable<T>;

  /**
   * @brief  Concept that checks if a type is printable.
   * @remark "The type `IsPrintable`."
   */
  template <typename T>
  concept IsPrintable = requires(T type, std::ostream& os) {
    { os << type } -> std::same_as<std::ostream&>;
  };

  /**
   * @brief  Concept that checks if the subject type is the same as the candidate type.
   * @remark "The subject `IsSameAs` the candidate."
   */
  template <typename TCandidate, typename TSubject>
  concept IsSameAs = std::same_as<TCandidate, TSubject>;

  /**
   * @brief  Concept that checks if a type is signed.
   * @remark "The type `IsSigned`."
   */
  template <typename T>
  concept IsSigned = std::is_signed_v<T>;

  /**
   * @brief  Concept that checks if a type is unsigned.
   * @remark "The type `IsUnsigned`."
   */
  template <typename T>
  concept IsUnsigned = std::is_unsigned_v<T>;

  /*----------------------------------------------------------------------------------------------*\
  *| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Counters >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
  \*----------------------------------------------------------------------------------------------*/

  /**
   * @brief  Concept that checks if all subject types are not the same as the candidate type.
   * @remark "The subjects `AreNotSameAs` the candidate."
   */
  template <typename TCandidate, typename... TSubjects>
  concept AreNotSameAs = not AreSameAs<TCandidate, TSubjects...>;

  /**
   * @brief  Concept that checks if a type is non-arithmetic.
   * @remark "The type `IsNotArithmetic`."
   */
  template <typename T>
  concept IsNotArithmetic = not IsArithmetic<T>;

  /**
   * @brief  Concept that checks if a type is not constructible from a set of arguments.
   * @remark "The type `IsNotConstructibleFrom` the arguments."
   */
  template <typename T, typename... TArguments>
  concept IsNotConstructibleFrom = not IsConstructibleFrom<T, TArguments...>;

  /**
   * @brief  Concept that checks if a callable is not invocable with a set of arguments.
   * @remark "The callable `IsNotInvocableWith` the arguments."
   */
  template <typename TCallable, typename... TArguments>
  concept IsNotInvocableWith = not IsInvocableWith<TCallable, TArguments...>;

  /**
   * @brief  Concept that checks if a type is not movable.
   * @remark "The type `IsNotMovable`."
   */
  template <typename T>
  concept IsNotMovable = not IsMovable<T>;

  /**
   * @brief  Concept that checks if a type is not printable.
   * @remark "The type `IsNotPrintable`."
   */
  template <typename T>
  concept IsNotPrintable = not IsPrintable<T>;

  /**
   * @brief  Concept that checks if the subject type is not the same as the candidate type.
   * @remark "The subject `IsNotSameAs` the candidate."
   */
  template <typename TCandidate, typename TSubject>
  concept IsNotSameAs = not IsSameAs<TCandidate, TSubject>;

  /**
   * @brief  Concept that checks if a type is not signed.
   * @remark "The type `IsNotSigned`."
   */
  template <typename T>
  concept IsNotSigned = not IsSigned<T>;

  /**
   * @brief  Concept that checks if a type is not unsigned.
   * @remark "The type `IsNotUnsigned`."
   */
  template <typename T>
  concept IsNotUnsigned = not IsUnsigned<T>;
} // namespace fn
