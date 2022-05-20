#include "liblogs/writers/file_writer.hpp"
#include "liblogs/formatter.hpp"

LIBLOGS_BEGIN_NAMESPACE

file_writer::file_writer()
    : writer(nullptr)
{}

file_writer::file_writer(std::shared_ptr<formatter> formatter)
    : writer(formatter)
{}

bool file_writer::initialize(const char* file_path, bool append)
{
    file_.open(file_path, std::ios_base::out|(append ? std::ios_base::app : std::ios_base::trunc));
    return file_.is_open();
}

void file_writer::write(time_t time, type t,
                        category::value_type category,
                        level::value_type level, const std::string &content)
{
    if ((category_mask_ & category) != 0 && level <= max_level_)
    {
        if (file_.is_open())
        {
            formatter_->format(file_, time, t, level, content);
            file_ << std::endl;
            file_.flush();
        }
    }
}

LIBLOGS_END_NAMESPACE
