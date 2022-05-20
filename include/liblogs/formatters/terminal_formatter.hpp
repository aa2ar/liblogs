// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_TERMINAL_FORMATTER__INCLUDED
#define LIBLOGS_TERMINAL_FORMATTER__INCLUDED

#include "liblogs/formatter.hpp"
#include <ostream>

LIBLOGS_BEGIN_NAMESPACE

class terminal_formatter : public formatter
{
public:
    terminal_formatter();
    void set_type_text(type t, std::string&& text);

    virtual void format(std::ostream& out, time_t time, type t, int level, std::string const& content);

protected:
    std::string const& get_type_text(type t) const;

private:
    std::string type_text_[6];
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_TERMINAL_FORMATTER__INCLUDED
