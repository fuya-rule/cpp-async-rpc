/// \file
/// \brief Compare operator for `const char *` value based on `strcmp`.
///
/// \copyright
///   Copyright 2018 by Google Inc. All Rights Reserved.
///
/// \copyright
///   Licensed under the Apache License, Version 2.0 (the "License"); you may
///   not use this file except in compliance with the License. You may obtain a
///   copy of the License at
///
/// \copyright
///   http://www.apache.org/licenses/LICENSE-2.0
///
/// \copyright
///   Unless required by applicable law or agreed to in writing, software
///   distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
///   WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
///   License for the specific language governing permissions and limitations
///   under the License.

#ifndef INCLUDE_ASH_CONST_CHAR_PTR_COMPARE_H_
#define INCLUDE_ASH_CONST_CHAR_PTR_COMPARE_H_

namespace ash {

struct const_char_ptr_compare {
  bool operator()(const char* a, const char* b) const;
};
}  // namespace ash

#endif  // INCLUDE_ASH_CONST_CHAR_PTR_COMPARE_H_
