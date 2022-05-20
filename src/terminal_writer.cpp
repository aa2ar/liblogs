#include "liblogs/writers/terminal_writer.hpp"
#include "liblogs/formatter.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

LIBLOGS_BEGIN_NAMESPACE

terminal_writer::terminal_writer()
    : writer(nullptr)
{}

terminal_writer::terminal_writer(std::shared_ptr<formatter> formatter, uint64_t category_mask)
    : writer(formatter, category_mask)
{}

void terminal_writer::write(time_t time,
                            type t,
                            category::value_type category,
                            level::value_type level,
                            std::string const& content)
{
    if ((category_mask_ & category) != 0 && level <= max_level_)
    {
        formatter_->format(std::cout, time, t, level, content);
        std::cout << std::endl;
    }
}

LIBLOGS_END_NAMESPACE
