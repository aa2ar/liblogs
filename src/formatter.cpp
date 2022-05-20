#include "liblogs/formatter.hpp"
#include <ctime>
#include <iomanip>

void LIBLOGS_NAMESPACE::formatter::format(std::ostream &out, time_t time, type t, level::value_type level, std::string const& content)
{
    out << std::put_time(std::localtime(&time), "%D %T ")
        << "" << static_cast<unsigned>(t) << " " << level << " " << content;
}
