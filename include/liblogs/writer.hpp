// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_WRITER__INCLUDED
#define LIBLOGS_WRITER__INCLUDED

#include "liblogsglobal.hpp"
#include "types.hpp"
#include <memory>
#include <atomic>
#include <mutex>
#include <ctime>
#include <string>

LIBLOGS_BEGIN_NAMESPACE

class formatter;

class writer
{
public:
    //writer() = default;
    explicit writer(std::shared_ptr<formatter> formatter, category::value_type = category::all().value);
    virtual ~writer() = default;

    virtual void write(time_t time, type t,
                       category::value_type category,
                       level::value_type level, std::string const& content) = 0;

protected:
    std::shared_ptr<formatter> formatter_;

private:
    std::mutex m_;
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_WRITER__INCLUDED
