// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_FILE_WRITER__INCLUDED
#define LIBLOGS_FILE_WRITER__INCLUDED

#include "liblogs/writer.hpp"
#include "liblogs/control.hpp"
#include <fstream>

LIBLOGS_BEGIN_NAMESPACE

class file_writer
        : public writer
        , public control
{
public:
    enum
    {
        append   = true,
        truncate = false
    };

    file_writer();
    explicit file_writer(std::shared_ptr<formatter> formatter);
    bool initialize(char const* file_path, bool = append);

    void write(time_t time, type t,
               category::value_type category,
               level::value_type level, std::string const& content);
private:
    std::ofstream file_;
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_FILE_WRITER__INCLUDED
