#include "liblogs/formatters/colored_terminal_formatter.hpp"
#include "colors.hpp"
#include <ctime>
#include <iomanip>

LIBLOGS_BEGIN_NAMESPACE

colored_terminal_formatter::colored_terminal_formatter()
    : terminal_formatter()
{
    color_values_[reset]        = reset_color_str;
    color_values_[black]        = black_color_str;
    color_values_[gray]         = gray_color_str;
    color_values_[red]          = red_color_str;
    color_values_[green]        = green_color_str;
    color_values_[yellow]       = yellow_color_str;
    color_values_[blue]         = blue_color_str;
    color_values_[magenta]      = magenta_color_str;
    color_values_[cyan]         = cyan_color_str;
    color_values_[white]        = white_color_str;
    color_values_[bold_black]   = bold_black_color_str;
    color_values_[bold_gray]    = bold_gray_color_str;
    color_values_[bold_red]     = bold_red_color_str;
    color_values_[bold_green]   = bold_green_color_str;
    color_values_[bold_yellow]  = bold_yellow_color_str;
    color_values_[bold_blue]    = bold_blue_color_str;
    color_values_[bold_magenta] = bold_magenta_color_str;
    color_values_[bold_cyan]    = bold_cyan_color_str;
    color_values_[bold_white]   = bold_white_color_str;

    for (int i = 0; i < 6; ++i)
        type_color_[i] = reset;
}

void colored_terminal_formatter::set_type_color(type t, color c)
{
    if (c < max_color)
    {
        switch (t)
        {
        case type::trace:   type_color_[0] = c; break;
        case type::debug:   type_color_[1] = c; break;
        case type::info:    type_color_[2] = c; break;
        case type::warning: type_color_[3] = c; break;
        case type::error:   type_color_[4] = c; break;
        case type::critical:type_color_[5] = c; break;
        default:;
        }
    }
}

std::string const& colored_terminal_formatter::get_type_color(type t) const
{
    switch (t)
    {
    case type::trace:   return color_values_[type_color_[0]];
    case type::debug:   return color_values_[type_color_[1]];
    case type::info:    return color_values_[type_color_[2]];
    case type::warning: return color_values_[type_color_[3]];
    case type::error:   return color_values_[type_color_[4]];
    case type::critical:return color_values_[type_color_[5]];
    default:;
    }
    return color_values_[reset];
}

void colored_terminal_formatter::format(std::ostream& out, time_t time, type t, int level, std::string const& content)
{
    //terminal_formatter::format(out, time, t, level, content);
    out << std::put_time(std::localtime(&time), "%D %T ");
    out << get_type_color(t);
    out << get_type_text(t);
    out << color_values_[reset] << " " << level << " " << content;
}

LIBLOGS_END_NAMESPACE
