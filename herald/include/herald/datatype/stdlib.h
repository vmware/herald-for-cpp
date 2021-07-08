//  Copyright 2020-2021 Herald Project Contributors
//  SPDX-License-Identifier: Apache-2.0
//

#ifndef HERALD_STDLIB_H
#define HERALD_STDLIB_H

#include <utility>

/**
 * C++ STDLIB extensions for Herald patterns.
 * Public in case you'd like to re-use them.
 * Part of the public API, and thus can be relied upon in future to be here
 */
namespace std
{
  // template<typename T1, typename T2>
  // struct hash<std::pair<T1,T2>>
  // {
  //   size_t operator()(const std::pair<T1,T2>& v) const
  //   {
  //     return std::hash<T1>()(v.first) ^ std::hash<T2>()(v.second);
  //   }
  // };
}

#endif
