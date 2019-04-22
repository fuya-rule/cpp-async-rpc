/// \file
/// \brief Channel descriptor wrapper.
///
/// \copyright
///   Copyright 2019 by Google LLC.
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

#include "lasr/pipe.h"
#include "lasr/errors.h"
#ifndef ESP_PLATFORM
#include <unistd.h>
#else  // ESP_PLATFORM
#include "lasr/address.h"
#include "lasr/address_resolver.h"
#include "lasr/socket.h"
#endif  // ESP_PLATFORM

namespace lasr {

void pipe(channel fds[2]) {
#ifndef ESP_PLATFORM
  int fd[2];
  if (::pipe(fd)) throw_io_error("Error creating pipe pair");
  fds[0].reset(fd[0]);
  fds[1].reset(fd[1]);
#else   // ESP_PLATFORM
  auto addrs = address_resolver::get().resolve(endpoint().datagram());
  if (addrs.empty()) {
    throw errors::internal_error("Can't get loopback address");
  }
  auto addr = *(addrs.begin());
  fds[0] = socket(addr);
  fds[1] = socket(addr);
  fds[0].bind(addr);
  fds[1].bind(addr);
  fds[0].make_non_blocking(true);
  fds[1].make_non_blocking(true);
  fds[1].connect(fds[0].own_addr());
#endif  // ESP_PLATFORM
}

}  // namespace lasr
