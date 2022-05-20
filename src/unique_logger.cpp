#include "liblogs/loggers/unique_logger.hpp"
#include "liblogs/logs.hpp"
#include "output.hpp"

LIBLOGS_BEGIN_NAMESPACE

unique_logger::unique_logger()
    : out_(new output)
{}

unique_logger::unique_logger(std::vector<std::shared_ptr<writer>> writers)
    : unique_logger()
{
    out_->initialize(std::move(writers));
}

void unique_logger::initialize(std::vector<std::shared_ptr<writer>> writers)
{
    out_->initialize(std::move(writers));
}

void unique_logger::set_max_level(int level)
{
    out_->set_max_level(level);
}

unique_logger::~unique_logger()
{
    out_->finalize();
}

message unique_logger::trace(level lvl)
{
    return log_write(out_.get(), type::trace, category::all(), lvl);
}

message unique_logger::debug(level lvl)
{
    return log_write(out_.get(), type::debug, category::all(), lvl);
}

message unique_logger::info(level lvl)
{
    return log_write(out_.get(), type::info, category::all(), lvl);
}

message unique_logger::warning(level lvl)
{
    return log_write(out_.get(), type::warning, category::all(), lvl);
}

message unique_logger::error(level lvl)
{
    return log_write(out_.get(), type::error, category::all(), lvl);
}

message unique_logger::critical(level lvl)
{
    return log_write(out_.get(), type::critical, category::all(), lvl);
}

message unique_logger::trace(category cat, level lvl)
{
    return log_write(out_.get(), type::trace, cat, lvl);
}

message unique_logger::debug(category cat, level lvl)
{
    return log_write(out_.get(), type::debug, cat, lvl);
}

message unique_logger::info(category cat, level lvl)
{
    return log_write(out_.get(), type::info, cat, lvl);
}

message unique_logger::warning(category cat, level lvl)
{
    return log_write(out_.get(), type::warning, cat, lvl);
}

message unique_logger::error(category cat, level lvl)
{
    return log_write(out_.get(), type::error, category::all(), lvl);
}

message unique_logger::critical(category cat, level lvl)
{
    return log_write(out_.get(), type::critical, cat, lvl);
}

void unique_logger::set_max_level(level lvl)
{
    out_->set_max_level(lvl.value);
}

void unique_logger::set_category_mask(category::value_type mask)
{
    out_->set_category_mask(mask);
}

LIBLOGS_END_NAMESPACE
