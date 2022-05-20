// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_TYPE__INCLUDED
#define LIBLOGS_TYPE__INCLUDED

#include <cstdint>
#include "liblogsglobal.hpp"

LIBLOGS_BEGIN_NAMESPACE

enum class type
{
    trace    = 0,
    debug    = 1,
    info     = 2,
    warning  = 3,
    error    = 4,
    critical = 5
};

struct category
{
    typedef uint64_t value_type;
    value_type const value;
    category(value_type val) : value(val) {}
    static category all();
    static category make(uint8_t bit_num);
};

struct level
{
    typedef int value_type;
    value_type const value;
    level(value_type lvl) : value(lvl) {}
    static level max();
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_TYPE__INCLUDED
