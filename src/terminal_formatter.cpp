#include "liblogs/formatters/terminal_formatter.hpp"
#include <ctime>
#include <iomanip>

LIBLOGS_BEGIN_NAMESPACE

terminal_formatter::terminal_formatter()
{
    type_text_[0] = "TRC";
    type_text_[1] = "DBG";
    type_text_[2] = "INF";
    type_text_[3] = "WRN";
    type_text_[4] = "ERR";
    type_text_[5] = "CRI";
}

void terminal_formatter::set_type_text(type t, std::string&& text)
{
    switch (t)
    {
    case type::trace:   type_text_[0] = text; break;
    case type::debug:   type_text_[1] = text; break;
    case type::info:    type_text_[2] = text; break;
    case type::warning: type_text_[3] = text; break;
    case type::error:   type_text_[4] = text; break;
    case type::critical:type_text_[5] = text; break;
    default:;
    }
}

void terminal_formatter::format(std::ostream &out, time_t time, type t, int level, std::string const& content)
{
    out << std::put_time(std::localtime(&time), "%D %T ")
        << "" << get_type_text(t) << " " << level << " " << content;
}

std::string const& terminal_formatter::get_type_text(type t) const
{
    switch (t)
    {
    case type::trace:   return type_text_[0];
    case type::debug:   return type_text_[1];
    case type::info:    return type_text_[2];
    case type::warning: return type_text_[3];
    case type::error:   return type_text_[4];
    case type::critical:return type_text_[5];
    default:;
    }
    static std::string unknown;
    return unknown;
}

LIBLOGS_END_NAMESPACE
