// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_LOGS__INCLUDED
#define LIBLOGS_LOGS__INCLUDED

#include <memory>
#include <vector>
#include <sstream>
#include <limits>
#include "liblogsglobal.hpp"
#include "types.hpp"
#include "message.hpp"

LIBLOGS_BEGIN_NAMESPACE

message trace(level = level(0));
message debug(level = level(0));
message info(level = level(0));
message warning(level = level(0));
message error(level = level(0));
message critical(level = level(0));

message trace(category, level = level(0));
message debug(category, level = level(0));
message info(category, level = level(0));
message warning(category, level = level(0));
message error(category, level = level(0));
message critical(category, level = level(0));

void initialize(std::vector<std::shared_ptr<writer>> = {});
void finalize();
void set_max_level(int level);
void set_category_mask(uint64_t mask);

// helper
message log_write(output* out, type t, category cat, level lvl);

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_LOGS__INCLUDED
