#include "liblogs/logs.hpp"
#include "colors.hpp"
#include "output.hpp"
#include <ctime>
#include <cassert>

LIBLOGS_BEGIN_NAMESPACE

output out;

category category::all()
{
    return category(std::numeric_limits<value_type>::max());
}

level level::max()
{
    return level(std::numeric_limits<level::value_type>::max());
}

category category::make(uint8_t bit_num)
{
    if (bit_num == 0 || bit_num > 64) throw std::invalid_argument("category::make() argument value should be in 1..64");
    return category((value_type)0x01 << (bit_num - 1));
}

message::message(type t, category cat, level lvl)
    : message(&out, t, cat, lvl)
{}

message::message(output* out, type t, category cat, level lvl)
    : out_(out)
    , time_(time(nullptr))
    , type_(t)
    , category_(cat)
    , level_(lvl)
{}

bool message::enabled() const
{
    return (out_ && (level_.value <= out_->max_level()));
}

message::message(message&& other)
    : out_(other.out_)
    , type_(other.type_)
    , category_(other.category_)
    , level_(other.level_)
    , ss_(std::move(other.ss_))
{
    other.out_ = nullptr;
}

message::~message()
{
    if (out_)
    {
        std::string s(std::move(ss_.str()));
        if (!s.empty()) out_->write(time_, type_, category_.value, level_.value, std::move(s));
    }
}

message log_write(output* out, type t, category cat, level lvl)
{
    return message(out, t, cat, lvl);
}

message trace(level lvl)
{
    return log_write(&out, type::trace, category::all(), lvl);
}

message debug(level lvl)
{
    return log_write(&out, type::debug, category::all(), lvl);
}

message info(level lvl)
{
    return log_write(&out, type::info, category::all(), lvl);
}

message warning(level lvl)
{
    return log_write(&out, type::warning, category::all(), lvl);
}

message error(level lvl)
{
    return log_write(&out, type::error, category::all(), lvl);
}

message critical(level lvl)
{
    return log_write(&out, type::critical, category::all(), lvl);
}

message trace(category cat, level lvl)
{
    return log_write(&out, type::trace, cat, lvl);
}

message debug(category cat, level lvl)
{
    return log_write(&out, type::debug, cat, lvl);
}

message info(category cat, level lvl)
{
    return log_write(&out, type::info, cat, lvl);
}

message warning(category cat, level lvl)
{
    return log_write(&out, type::warning, cat, lvl);
}

message error(category cat, level lvl)
{
    return log_write(&out, type::error, cat, lvl);
}

message critical(category cat, level lvl)
{
    return log_write(&out, type::critical, cat, lvl);
}

void initialize(std::vector<std::shared_ptr<writer>> writers)
{
    out.initialize(std::move(writers));
}

void set_max_level(int level)
{
    out.set_max_level(level);
}

void set_category_mask(uint64_t mask)
{
    out.set_category_mask(mask);
}

void finalize()
{
    out.finalize();
}

LIBLOGS_END_NAMESPACE
