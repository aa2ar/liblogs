#include "liblogs/writers/syslog_writer.hpp"
#include <syslog.h>

LIBLOGS_BEGIN_NAMESPACE

static
int syslog_priority(type t)
{
    switch (t)
    {
    case type::critical: return LOG_CRIT;
    case type::debug:    return LOG_DEBUG;
    case type::error:    return LOG_ERR;
    case type::info:     return LOG_INFO;
    case type::warning:  return LOG_WARNING;
    default:;
    }
    return -1;
}

syslog_writer::syslog_writer()
    : writer(nullptr)
{}

syslog_writer::~syslog_writer()
{
    closelog();
}

void syslog_writer::write(time_t time, type t,
                          category::value_type category,
                          level::value_type level,
                          std::string const& content)
{
    (void)time;
    (void)category;
    (void)level;
    if ((category_mask_ & category) != 0 && level <= max_level_)
    {
        int priority = syslog_priority(t);
        if (priority > -1)
            syslog(priority, "%s", content.c_str());
    }
}

LIBLOGS_END_NAMESPACE
