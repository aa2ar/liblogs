// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_COLORED_TERMINAL_FORMATTER__INCLUDED
#define LIBLOGS_COLORED_TERMINAL_FORMATTER__INCLUDED

#include "terminal_formatter.hpp"

LIBLOGS_BEGIN_NAMESPACE

class colored_terminal_formatter : public terminal_formatter
{
public:
    enum color
    {
        reset,
        black, gray, red, green, yellow, blue, magenta, cyan, white,
        bold_black, bold_gray, bold_red, bold_green, bold_yellow, bold_blue, bold_magenta, bold_cyan, bold_white,
        max_color
    };
    colored_terminal_formatter();
    void set_type_color(type t, color c);

protected:
    void format(std::ostream& out, time_t time, type t, int level, std::string const& content) override;

private:
    std::string s;
    color       type_color_[6];
    std::string color_values_[max_color];
    std::string const& get_type_color(type t) const;
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_COLORED_TERMINAL_WRITER__INCLUDED
