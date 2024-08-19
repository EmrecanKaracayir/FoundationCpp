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
   * @tparam T The type of the elements stored in the array.
   * @tparam size The number of elements in the array.
   */
  template <typename T, size size>
  using arr = std::array<T, size>;

  /**
   * @brief  A type that represents a dynamic array of elements with customizable allocator.
   * @tparam T The type of the elements stored in the vector.
   * @tparam TAllocator The type of the allocator used for managing the vector's memory. Defaults to
   *         `std::allocator<T>`.
   */
  template <typename T, typename TAllocator = std::allocator<T>>
  using vec = std::vector<T, TAllocator>;

  /**
   * @brief  A type alias for a bidirectional queue with customizable allocator.
   * @tparam T The type of the elements stored in the bque.
   * @tparam TAllocator The type of the allocator used for managing the deque's memory. Defaults to
   *         `std::allocator<T>`.
   */
  template <typename T, typename TAllocator = std::allocator<T>>
  using bque = std::deque<T, TAllocator>;

  /**
   * @brief  A type alias for a singly linked list with customizable allocator.
   * @tparam T The type of the elements stored in the sll.
   * @tparam TAllocator The type of the allocator used for managing the list's memory. Defaults to
   *         `std::allocator<T>`.
   */
  template <typename T, typename TAllocator = std::allocator<T>>
  using sll = std::forward_list<T, TAllocator>;

  /**
   * @brief  A type alias for a doubly linked list with customizable allocator.
   * @tparam T The type of the elements stored in the dll.
   * @tparam TAllocator The type of the allocator used for managing the list's memory. Defaults to
   *         `std::allocator<T>`.
   */
  template <typename T, typename TAllocator = std::allocator<T>>
  using dll = std::list<T, TAllocator>;

  /*----------------------------------------------------------------------------------------------*\
  *| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Relational >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
  \*----------------------------------------------------------------------------------------------*/

  /**
   * @brief  A type alias for a map with customizable key, value, comparator, and allocator.
   * @tparam TKey The type of the keys stored in the map.
   * @tparam TValue The type of the values stored in the map.
   * @tparam TCompare The type of the comparator used for sorting the map. Defaults to
   *         `std::less<TKey>`.
   * @tparam TAllocator The type of the allocator used for managing the map's memory. Defaults to
   *         `std::allocator<pair<const TKey, TValue>>`.
   */
  template <
    typename TKey,
    typename TValue,
    typename TCompare   = std::less<TKey>,
    typename TAllocator = std::allocator<pair<const TKey, TValue>>>
  using map = std::map<TKey, TValue, TCompare, TAllocator>;

  /**
   * @brief  A type alias for an unordered map with customizable key, value, hash, key equality, and
   *         allocator.
   * @tparam TKey The type of the keys stored in the map.
   * @tparam TValue The type of the values stored in the map.
   * @tparam THash The type of the hash function used for hashing the keys. Defaults to
   *         `std::hash<TKey>`.
   * @tparam TKeyEqual The type of the key equality function used for comparing the keys. Defaults
   *         to `std::equal_to<TKey>`.
   * @tparam TAllocator The type of the allocator used for managing the map's memory. Defaults to
   *         `std::allocator<pair<const TKey, TValue>>`.
   */
  template <
    typename TKey,
    typename TValue,
    typename THash      = std::hash<TKey>,
    typename TKeyEqual  = std::equal_to<TKey>,
    typename TAllocator = std::allocator<pair<const TKey, TValue>>>
  using umap = std::unordered_map<TKey, TValue, THash, TKeyEqual, TAllocator>;

  /**
   * @brief  A type alias for a multimap with customizable key, value, comparator, and allocator.
   * @tparam TKey The type of the keys stored in the multimap.
   * @tparam TValue The type of the values stored in the multimap.
   * @tparam TCompare The type of the comparator used for sorting the multimap. Defaults to
   *         `std::less<TKey>`.
   * @tparam TAllocator The type of the allocator used for managing the multimap's memory. Defaults
   *         to `std::allocator<pair<const TKey, TValue>>`.
   */
  template <
    typename TKey,
    typename TValue,
    typename TCompare   = std::less<TKey>,
    typename TAllocator = std::allocator<pair<const TKey, TValue>>>
  using mmap = std::multimap<TKey, TValue, TCompare, TAllocator>;

  /**
   * @brief  A type alias for an unordered multimap with customizable key, value, hash, key
   *         equality, and allocator.
   * @tparam TKey The type of the keys stored in the multimap.
   * @tparam TValue The type of the values stored in the multimap.
   * @tparam THash The type of the hash function used for hashing the keys. Defaults to
   *         `std::hash<TKey>`.
   * @tparam TKeyEqual The type of the key equality function used for comparing the keys. Defaults
   *         to `std::equal_to<TKey>`.
   * @tparam TAllocator The type of the allocator used for managing the multimap's memory. Defaults
   *         to `std::allocator<pair<const TKey, TValue>>`.
   */
  template <
    typename TKey,
    typename TValue,
    typename THash      = std::hash<TKey>,
    typename TKeyEqual  = std::equal_to<TKey>,
    typename TAllocator = std::allocator<pair<const TKey, TValue>>>
  using ummap = std::unordered_multimap<TKey, TValue, THash, TKeyEqual, TAllocator>;

  /**
   * @brief  A type alias for a set with customizable type, comparator, and allocator.
   * @tparam T The type of the elements stored in the set.
   * @tparam TCompare The type of the comparator used for sorting the set. Defaults to
   *         `std::less<T>`.
   * @tparam TAllocator The type of the allocator used for managing the set's memory. Defaults to
   *         `std::allocator<T>`.
   */
  template <typename T, typename TCompare = std::less<T>, typename TAllocator = std::allocator<T>>
  using set = std::set<T, TCompare, TAllocator>;

  /**
   * @brief  A type alias for an unordered set with customizable type, hash, key equality, and
   *         allocator.
   * @tparam T The type of the elements stored in the set.
   * @tparam THash The type of the hash function used for hashing the elements. Defaults to
   *         `std::hash<T>`.
   * @tparam TKeyEqual The type of the key equality function used for comparing the elements.
   *         Defaults to `std::equal_to<T>`.
   * @tparam TAllocator The type of the allocator used for managing the set's memory. Defaults to
   *         `std::allocator<T>`.
   */
  template <
    typename T,
    typename THash      = std::hash<T>,
    typename TKeyEqual  = std::equal_to<T>,
    typename TAllocator = std::allocator<T>>
  using uset = std::unordered_set<T, THash, TKeyEqual, TAllocator>;

  /**
   * @brief  A type alias for a multiset with customizable type, comparator, and allocator.
   * @tparam T The type of the elements stored in the multiset.
   * @tparam TCompare The type of the comparator used for sorting the multiset. Defaults to
   *         `std::less<T>`.
   * @tparam TAllocator The type of the allocator used for managing the multiset's memory. Defaults
   *         to `std::allocator<T>`.
   */
  template <typename T, typename TCompare = std::less<T>, typename TAllocator = std::allocator<T>>
  using mset = std::multiset<T, TCompare, TAllocator>;

  /**
   * @brief  A type alias for an unordered multiset with customizable type, hash, key equality, and
   *         allocator.
   * @tparam T The type of the elements stored in the multiset.
   * @tparam THash The type of the hash function used for hashing the elements. Defaults to
   *         `std::hash<T>`.
   * @tparam TKeyEqual The type of the key equality function used for comparing the elements.
   *         Defaults to `std::equal_to<T>`.
   * @tparam TAllocator The type of the allocator used for managing the multiset's memory. Defaults
   *         to `std::allocator<T>`.
   */
  template <
    typename T,
    typename THash      = std::hash<T>,
    typename TKeyEqual  = std::equal_to<T>,
    typename TAllocator = std::allocator<T>>
  using umset = std::unordered_multiset<T, THash, TKeyEqual, TAllocator>;

  /*----------------------------------------------------------------------------------------------*\
  *| <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Adapters >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> |*
  \*----------------------------------------------------------------------------------------------*/

  /**
   * @brief  A type alias for a stack with customizable type and container.
   * @tparam T The type of the elements stored in the stack.
   * @tparam TContainer The type of the container used for managing the stack's memory. Defaults to
   *         `bque<T>`.
   */
  template <typename T, typename TContainer = bque<T>>
  using stk = std::stack<T, TContainer>;

  /**
   * @brief  A type alias for a queue with customizable type and container.
   * @tparam T The type of the elements stored in the queue.
   * @tparam TContainer The type of the container used for managing the queue's memory. Defaults to
   *         `bque<T>`.
   */
  template <typename T, typename TContainer = bque<T>>
  using que = std::queue<T, TContainer>;

  /**
   * @brief  A type alias for a priority queue with customizable type, container, and comparator.
   * @tparam T The type of the elements stored in the priority queue.
   * @tparam TContainer The type of the container used for managing the priority queue's memory.
   *         Defaults to `vec<T>`.
   * @tparam TCompare The type of the comparator used for sorting the priority queue. Defaults to
   *         `std::less<typename TContainer::value_type>`.
   */
  template <
    typename T,
    typename TContainer = vec<T>,
    typename TCompare   = std::less<typename TContainer::value_type>>
  using pque = std::priority_queue<T, TContainer, TCompare>;
} // namespace fn
