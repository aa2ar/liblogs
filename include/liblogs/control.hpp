// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_CONTROL__INCLUDED
#define LIBLOGS_CONTROL__INCLUDED

#include "types.hpp"
#include <atomic>

LIBLOGS_BEGIN_NAMESPACE

class control
{
public:
    control();
    virtual ~control() = default;

    void set_max_level(level lvl);
    level max_level() const;

    void set_category_mask(category::value_type mask);
    category::value_type category_mask() const;

protected:
    std::atomic<category::value_type> category_mask_;
    std::atomic<level::value_type>    max_level_;
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_CONTROL__INCLUDED
