// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_FORMATTER__INCLUDED
#define LIBLOGS_FORMATTER__INCLUDED

#include "types.hpp"
#include <ostream>

LIBLOGS_BEGIN_NAMESPACE

class formatter
{
public:
    virtual void format(std::ostream& out, time_t time, type t, int level, std::string const& content);
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_FORMATTER__INCLUDED
