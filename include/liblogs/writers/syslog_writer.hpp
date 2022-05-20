// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_SYSLOG_WRITER__INCLUDED
#define LIBLOGS_SYSLOG_WRITER__INCLUDED

#include "liblogs/writer.hpp"
#include "liblogs/control.hpp"
#include <vector>
#include <sstream>

LIBLOGS_BEGIN_NAMESPACE

class syslog_writer
        : public writer
        , public control
{
public:
    syslog_writer();
    ~syslog_writer();

protected:
    void write(time_t time, type t,
               category::value_type category,
               level::value_type level,
               std::string const& content) override;

    std::ostringstream output_;
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_SYSLOG_WRITER__INCLUDED
