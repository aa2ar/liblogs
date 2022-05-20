#include "liblogs/loggers/global_logger.hpp"

LIBLOGS_BEGIN_NAMESPACE

message logger::trace(level lvl)
{
    return LIBLOGS_NAMESPACE::trace(lvl);
}

message logger::debug(level lvl)
{
    return LIBLOGS_NAMESPACE::debug(lvl);
}

message logger::info(level lvl)
{
    return LIBLOGS_NAMESPACE::info(category::all(), lvl);
}

message logger::warning(level lvl)
{
    return LIBLOGS_NAMESPACE::warning(lvl);
}

message logger::error(level lvl)
{
    return LIBLOGS_NAMESPACE::error(lvl);
}

message logger::critical(level lvl)
{
    return LIBLOGS_NAMESPACE::critical(lvl);
}

message logger::trace(category cat, level lvl)
{
    return LIBLOGS_NAMESPACE::trace(cat, lvl);
}

message logger::debug(category cat, level lvl)
{
    return LIBLOGS_NAMESPACE::debug(cat, lvl);
}

message logger::info(category cat, level lvl)
{
    return LIBLOGS_NAMESPACE::info(cat, lvl);
}

message logger::warning(category cat, level lvl)
{
    return LIBLOGS_NAMESPACE::warning(cat, lvl);
}

message logger::error(category cat, level lvl)
{
    return LIBLOGS_NAMESPACE::error(cat, lvl);
}

message logger::critical(category cat, level lvl)
{
    return LIBLOGS_NAMESPACE::critical(cat, lvl);
}

void global_logger::set_max_level(level lvl)
{
    LIBLOGS_NAMESPACE::set_max_level(lvl.value);
}

void global_logger::set_category_mask(category::value_type mask)
{
    LIBLOGS_NAMESPACE::set_category_mask(mask);
}

LIBLOGS_END_NAMESPACE
