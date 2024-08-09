#pragma once

#include "Foundation/_internal/Exception/_internal/concepts.hpp"
#include "Foundation/_internal/Exception/Name.ipp"
#include "Foundation/concepts.hpp"
#include "Foundation/types.hpp"
#include "Foundation/utilities.hpp"

#include <exception>
#include <ostream>
#include <source_location>
#include <utility>

namespace fn::_internal::Exception
{
  /**
   * @brief   A foundation class for custom exceptions with extended information and functionality.
   * @tparam  name The name of the exception.
   * @tparam  TContext The context of the exception.
   * @warning Use this class as a base for custom exceptions.
   */
  template <Name name, _internal::IsContext TContext>
  class Exception final : public std::exception
  {
  public:
    /*-----------------------------------------------------------------------------------+--------*\
    *| [public]: Constructors                                                            | PUBLIC |*
    \*-----------------------------------------------------------------------------------+--------*/

    /**
     * @brief Constructs an exception by copying another exception.
     * @param other Other exception to copy from.
     */
    Exception(const Exception& other) = default;

    /**
     * @brief Constructs an exception by moving another exception.
     * @param other Other exception to move from.
     */
    Exception(Exception&& other) noexcept = default;

    /**
     * @brief Constructs an exception without any message or context.
     */
    explicit Exception(
      const std::source_location& location = std::source_location::current()
    ) noexcept;

    /**
     * @brief Constructs an exception with a message.
     * @param message The message.
     */
    explicit Exception(
      fn::str&& message, const std::source_location& location = std::source_location::current()
    ) noexcept;

    /**
     * @brief Constructs an exception with a message and a context.
     * @param message The message.
     * @param context The context.
     */
    Exception(
      fn::str&&                   message,
      TContext&&                  context,
      const std::source_location& location = std::source_location::current()
    ) noexcept;

    /*-----------------------------------------------------------------------------------+--------*\
    *| [public]: Destructor                                                              | PUBLIC |*
    \*-----------------------------------------------------------------------------------+--------*/

    /**
     * @brief Destructs the exception.
     */
    ~Exception() override = default;

    /*-----------------------------------------------------------------------------------+--------*\
    *| [public]: Operators                                                               | PUBLIC |*
    \*-----------------------------------------------------------------------------------+--------*/

    /**
     * @brief   Assigns another exception to this exception by copying.
     * @param   other The other exception to copy from.
     * @returns The reference to this exception.
     */
    auto operator=(const Exception& other) -> Exception& = default;

    /**
     * @brief   Assigns another exception to this exception by moving.
     * @param   other The other exception to move from.
     * @returns The reference to this exception.
     */
    auto operator=(Exception&& other) noexcept -> Exception& = default;

    /*-----------------------------------------------------------------------------------+--------*\
    *| [public]: Methods                                                                 | PUBLIC |*
    \*-----------------------------------------------------------------------------------+--------*/

    /**
     * @brief   Accessor for the name of the exception.
     * @returns The name of the exception.
     */
    [[nodiscard]] auto what() const noexcept -> cstr override;

    /*-----------------------------------------------------------------------------------+--------*\
    *| [public]: Accessors                                                               | PUBLIC |*
    \*-----------------------------------------------------------------------------------+--------*/

    /**
     * @brief   Accessor for the message of the exception.
     * @returns The message of the exception.
     */
    [[nodiscard]] auto getMessage() const noexcept -> const fn::opt<fn::str>&;

    /**
     * @brief   Accessor for the context of the exception.
     * @returns The context of the exception.
     */
    [[nodiscard]] auto getContext() const noexcept -> const fn::opt<TContext>&;

    /**
     * @brief   Accessor for the location of the exception.
     * @returns The location of the exception.
     */
    [[nodiscard]] auto getLocation() const noexcept -> const std::source_location&;

  private:
    /*----------------------------------------------------------------------------------+---------*\
    *| [private]: Fields                                                                | PRIVATE |*
    \*----------------------------------------------------------------------------------+---------*/

    fn::opt<fn::str>     m_message;
    fn::opt<TContext>    m_context;
    std::source_location m_location;

    /*----------------------------------------------------------------------------------+---------*\
    *| [private]: Friends                                                               | PRIVATE |*
    \*----------------------------------------------------------------------------------+---------*/

    // NOLINTBEGIN(bugprone-exception-escape)

    /**
     * @brief   Prints the exception to an output stream.
     * @param   os The output stream.
     * @param   exception The exception.
     * @returns The output stream.
     */
    friend auto operator<<(std::ostream& os, const Exception& exception) noexcept -> std::ostream&
    {
#pragma warning(push)
#pragma warning(disable : 26'447 26'485)

      // NOLINTBEGIN(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)

      // Print exception name
      os << name.value << '\n';

      // NOLINTEND(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)

      // Print message if available
      if (const auto message{exception.m_message}; message.has_value())
      {
        os << "  Message: " << message.value() << '\n';
      }

      // Print context if available and not unit
      if (const auto context{exception.m_context}; context.has_value())
      {
        // Print context if not unit
        if constexpr (not IsSame<TContext, unit>)
        {
          os << "  Context: " << context.value() << '\n';
        }
      }

      // Print address
      os << "  Address: " << exception.m_location.file_name() << "(" << exception.m_location.line()
         << ":" << exception.m_location.column() << ")\n";

      // Print routine
      os << "  Routine: " << exception.m_location.function_name();

#pragma warning(pop)

      // Return output stream
      return os;
    }

    // NOLINTEND(bugprone-exception-escape)
  };
} // namespace fn::_internal::Exception

/*------------------------------------------------------------------------------------------------*\
*| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Implementation >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
\*------------------------------------------------------------------------------------------------*/

namespace fn::_internal::Exception
{
  /*-------------------------------------------------------------------------------------+--------*\
  *| [public]: Constructors                                                              | PUBLIC |*
  \*-------------------------------------------------------------------------------------+--------*/

  template <Name name, _internal::IsContext TContext>
  Exception<name, TContext>::Exception(const std::source_location& location) noexcept
    : m_location{location}
  {}

  template <Name name, _internal::IsContext TContext>
  Exception<name, TContext>::Exception(
    fn::str&& message, const std::source_location& location
  ) noexcept
    : m_message{std::move(message)}
    , m_location{location}
  {}

  template <Name name, _internal::IsContext TContext>
  Exception<name, TContext>::Exception(
    fn::str&& message, TContext&& context, const std::source_location& location
  ) noexcept
    : m_message{std::move(message)}
    , m_context{std::move(context)}
    , m_location{location}
  {}

  /*-------------------------------------------------------------------------------------+--------*\
  *| [public]: Methods                                                                   | PUBLIC |*
  \*-------------------------------------------------------------------------------------+--------*/

  template <Name name, _internal::IsContext TContext>
  [[nodiscard]] auto Exception<name, TContext>::what() const noexcept -> cstr
  {
#pragma warning(push)
#pragma warning(disable : 26'485)

    // NOLINTBEGIN(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)

    return name.value;

    // NOLINTEND(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)

#pragma warning(pop)
  }

  /*-------------------------------------------------------------------------------------+--------*\
  *| [public]: Accessors                                                                 | PUBLIC |*
  \*-------------------------------------------------------------------------------------+--------*/

  template <Name name, _internal::IsContext TContext>
  [[nodiscard]] auto Exception<name, TContext>::getMessage() const noexcept
    -> const fn::opt<fn::str>&
  {
    return m_message;
  }

  template <Name name, _internal::IsContext TContext>
  [[nodiscard]] auto Exception<name, TContext>::getContext() const noexcept
    -> const fn::opt<TContext>&
  {
    return m_context;
  }

  template <Name name, _internal::IsContext TContext>
  [[nodiscard]] auto Exception<name, TContext>::getLocation() const noexcept
    -> const std::source_location&
  {
    return m_location;
  }
} // namespace fn::_internal::Exception
