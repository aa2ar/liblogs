// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_TERMINAL_WRITER__INCLUDED
#define LIBLOGS_TERMINAL_WRITER__INCLUDED

#include "liblogs/writer.hpp"
#include "liblogs/control.hpp"
#include <vector>

LIBLOGS_BEGIN_NAMESPACE

class terminal_writer
        : public writer
        , public control
{
public:
    terminal_writer();
    explicit terminal_writer(std::shared_ptr<formatter> formatter, uint64_t category_mask = category::all().value);

    void write(time_t time, type t,
               category::value_type category,
               level::value_type level,
               std::string const& content) override;
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_TERMINAL_WRITER__INCLUDED
