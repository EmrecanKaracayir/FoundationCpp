#pragma once

#include "Foundation/types.hpp"
#include "Foundation/utilities.hpp"

#include <array>
#include <deque>
#include <forward_list>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace fn
{
  /*----------------------------------------------------------------------------------------------*\
  *| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Sequential >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
  \*----------------------------------------------------------------------------------------------*/

  /**
   * @brief  A type that represents a fixed-size array of elements.
   * @tparam Type The type of the elements stored in the array.
   * @tparam size The number of elements in the array.
   */
  template <typename Type, size size>
  using arr = std::array<Type, size>;

  /**
   * @brief  A type that represents a dynamic array of elements with customizable allocator.
   * @tparam Type The type of the elements stored in the vector.
   * @tparam Allocator The type of the allocator used for managing the vector's memory. Defaults to
   *         `std::allocator<Type>`.
   */
  template <typename Type, typename Allocator = std::allocator<Type>>
  using vec = std::vector<Type, Allocator>;

  /**
   * @brief  A type alias for a bidirectional queue with customizable allocator.
   * @tparam Type The type of the elements stored in the bque.
   * @tparam Allocator The type of the allocator used for managing the deque's memory. Defaults to
   *         `std::allocator<Type>`.
   */
  template <typename Type, typename Allocator = std::allocator<Type>>
  using bque = std::deque<Type, Allocator>;

  /**
   * @brief  A type alias for a singly linked list with customizable allocator.
   * @tparam Type The type of the elements stored in the sll.
   * @tparam Allocator The type of the allocator used for managing the list's memory. Defaults to
   *         `std::allocator<Type>`.
   */
  template <typename Type, typename Allocator = std::allocator<Type>>
  using sll = std::forward_list<Type, Allocator>;

  /**
   * @brief  A type alias for a doubly linked list with customizable allocator.
   * @tparam Type The type of the elements stored in the dll.
   * @tparam Allocator The type of the allocator used for managing the list's memory. Defaults to
   *         `std::allocator<Type>`.
   */
  template <typename Type, typename Allocator = std::allocator<Type>>
  using dll = std::list<Type, Allocator>;

  /*----------------------------------------------------------------------------------------------*\
  *| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Relational >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
  \*----------------------------------------------------------------------------------------------*/

  /**
   * @brief  A type alias for a map with customizable key, value, comparator, and allocator.
   * @tparam Key The type of the keys stored in the map.
   * @tparam Value The type of the values stored in the map.
   * @tparam Compare The type of the comparator used for sorting the map. Defaults to
   *         `std::less<Key>`.
   * @tparam Allocator The type of the allocator used for managing the map's memory. Defaults to
   *         `std::allocator<pair<const Key, Value>>`.
   */
  template <
    typename Key,
    typename Value,
    typename Compare   = std::less<Key>,
    typename Allocator = std::allocator<pair<const Key, Value>>>
  using map = std::map<Key, Value, Compare, Allocator>;

  /**
   * @brief  A type alias for an unordered map with customizable key, value, hash, key equality, and
   *         allocator.
   * @tparam Key The type of the keys stored in the map.
   * @tparam Value The type of the values stored in the map.
   * @tparam Hash The type of the hash function used for hashing the keys. Defaults to
   *         `std::hash<Key>`.
   * @tparam KeyEqual The type of the key equality function used for comparing the keys. Defaults to
   *         `std::equal_to<Key>`.
   * @tparam Allocator The type of the allocator used for managing the map's memory. Defaults to
   *         `std::allocator<pair<const Key, Value>>`.
   */
  template <
    typename Key,
    typename Value,
    typename Hash      = std::hash<Key>,
    typename KeyEqual  = std::equal_to<Key>,
    typename Allocator = std::allocator<pair<const Key, Value>>>
  using umap = std::unordered_map<Key, Value, Hash, KeyEqual, Allocator>;

  /**
   * @brief  A type alias for a multimap with customizable key, value, comparator, and allocator.
   * @tparam Key The type of the keys stored in the multimap.
   * @tparam Value The type of the values stored in the multimap.
   * @tparam Compare The type of the comparator used for sorting the multimap. Defaults to
   *         `std::less<Key>`.
   * @tparam Allocator The type of the allocator used for managing the multimap's memory. Defaults
   *         to `std::allocator<pair<const Key, Value>>`.
   */
  template <
    typename Key,
    typename Value,
    typename Compare   = std::less<Key>,
    typename Allocator = std::allocator<pair<const Key, Value>>>
  using mmap = std::multimap<Key, Value, Compare, Allocator>;

  /**
   * @brief  A type alias for an unordered multimap with customizable key, value, hash, key
   *         equality, and allocator.
   * @tparam Key The type of the keys stored in the multimap.
   * @tparam Value The type of the values stored in the multimap.
   * @tparam Hash The type of the hash function used for hashing the keys. Defaults to
   *         `std::hash<Key>`.
   * @tparam KeyEqual The type of the key equality function used for comparing the keys. Defaults to
   *         `std::equal_to<Key>`.
   * @tparam Allocator The type of the allocator used for managing the multimap's memory. Defaults
   *         to `std::allocator<pair<const Key, Value>>`.
   */
  template <
    typename Key,
    typename Value,
    typename Hash      = std::hash<Key>,
    typename KeyEqual  = std::equal_to<Key>,
    typename Allocator = std::allocator<pair<const Key, Value>>>
  using ummap = std::unordered_multimap<Key, Value, Hash, KeyEqual, Allocator>;

  /**
   * @brief  A type alias for a set with customizable type, comparator, and allocator.
   * @tparam Type The type of the elements stored in the set.
   * @tparam Compare The type of the comparator used for sorting the set. Defaults to
   *         `std::less<Type>`.
   * @tparam Allocator The type of the allocator used for managing the set's memory. Defaults to
   *         `std::allocator<Type>`.
   */
  template <
    typename Type,
    typename Compare   = std::less<Type>,
    typename Allocator = std::allocator<Type>>
  using set = std::set<Type, Compare, Allocator>;

  /**
   * @brief  A type alias for an unordered set with customizable type, hash, key equality, and
   *         allocator.
   * @tparam Type The type of the elements stored in the set.
   * @tparam Hash The type of the hash function used for hashing the elements. Defaults to
   *         `std::hash<Type>`.
   * @tparam KeyEqual The type of the key equality function used for comparing the elements.
   *         Defaults to `std::equal_to<Type>`.
   * @tparam Allocator The type of the allocator used for managing the set's memory. Defaults to
   *         `std::allocator<Type>`.
   */
  template <
    typename Type,
    typename Hash      = std::hash<Type>,
    typename KeyEqual  = std::equal_to<Type>,
    typename Allocator = std::allocator<Type>>
  using uset = std::unordered_set<Type, Hash, KeyEqual, Allocator>;

  /**
   * @brief  A type alias for a multiset with customizable type, comparator, and allocator.
   * @tparam Type The type of the elements stored in the multiset.
   * @tparam Compare The type of the comparator used for sorting the multiset. Defaults to
   *         `std::less<Type>`.
   * @tparam Allocator The type of the allocator used for managing the multiset's memory. Defaults
   *         to `std::allocator<Type>`.
   */
  template <
    typename Type,
    typename Compare   = std::less<Type>,
    typename Allocator = std::allocator<Type>>
  using mset = std::multiset<Type, Compare, Allocator>;

  /**
   * @brief  A type alias for an unordered multiset with customizable type, hash, key equality, and
   *         allocator.
   * @tparam Type The type of the elements stored in the multiset.
   * @tparam Hash The type of the hash function used for hashing the elements. Defaults to
   *         `std::hash<Type>`.
   * @tparam KeyEqual The type of the key equality function used for comparing the elements.
   *         Defaults to `std::equal_to<Type>`.
   * @tparam Allocator The type of the allocator used for managing the multiset's memory. Defaults
   *         to `std::allocator<Type>`.
   */
  template <
    typename Type,
    typename Hash      = std::hash<Type>,
    typename KeyEqual  = std::equal_to<Type>,
    typename Allocator = std::allocator<Type>>
  using umset = std::unordered_multiset<Type, Hash, KeyEqual, Allocator>;

  /*----------------------------------------------------------------------------------------------*\
  *| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Adapters >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
  \*----------------------------------------------------------------------------------------------*/

  /**
   * @brief  A type alias for a stack with customizable type and container.
   * @tparam Type The type of the elements stored in the stack.
   * @tparam Container The type of the container used for managing the stack's memory. Defaults to
   *         `bque<Type>`.
   */
  template <typename Type, typename Container = bque<Type>>
  using stk = std::stack<Type, Container>;

  /**
   * @brief  A type alias for a queue with customizable type and container.
   * @tparam Type The type of the elements stored in the queue.
   * @tparam Container The type of the container used for managing the queue's memory. Defaults to
   *         `bque<Type>`.
   */
  template <typename Type, typename Container = bque<Type>>
  using que = std::queue<Type, Container>;

  /**
   * @brief  A type alias for a priority queue with customizable type, container, and comparator.
   * @tparam Type The type of the elements stored in the priority queue.
   * @tparam Container The type of the container used for managing the priority queue's memory.
   *         Defaults to `vec<Type>`.
   * @tparam Compare The type of the comparator used for sorting the priority queue. Defaults to
   *         `std::less<typename Container::value_type>`.
   */
  template <
    typename Type,
    typename Container = vec<Type>,
    typename Compare   = std::less<typename Container::value_type>>
  using pque = std::priority_queue<Type, Container, Compare>;
} // namespace fn
