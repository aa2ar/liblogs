// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_MESSAGE__INCLUDED
#define LIBLOGS_MESSAGE__INCLUDED

#include <memory>
#include <vector>
#include <sstream>
#include <limits>
#include "liblogsglobal.hpp"
#include "types.hpp"

LIBLOGS_BEGIN_NAMESPACE

class output;
class writer;

class message
{
public:
    message(message&&);
    ~message();
    template<typename T> message& operator<<(T const& msg)
    {
        if (enabled()) ss_ << msg;
        return *this;
    }
private:
    friend message log_write(output*, type, category, level);
    message(type t, category, level);
    message(output*, type t, category cat, level lvl);
    message(message const&) = delete;
    message& operator=(message const&) = delete;
    bool enabled() const;
    output*  out_;
    time_t   time_;
    type     type_;
    category category_;
    level    level_;
    std::ostringstream ss_;
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_MESSAGE__INCLUDED
