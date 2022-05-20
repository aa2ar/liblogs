// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_LOGGER__INCLUDED
#define LIBLOGS_LOGGER__INCLUDED

#include "logs.hpp"

LIBLOGS_BEGIN_NAMESPACE

class logger
{
public:
    virtual ~logger() = default;

    virtual message trace(level = level(0)) = 0;
    virtual message debug(level = level(0)) = 0;
    virtual message info(level = level(0)) = 0;
    virtual message warning(level = level(0)) = 0;
    virtual message error(level = level(0)) = 0;
    virtual message critical(level = level(0)) = 0;

    virtual message trace(category, level = level(0)) = 0;
    virtual message debug(category, level = level(0)) = 0;
    virtual message info(category, level = level(0)) = 0;
    virtual message warning(category, level = level(0)) = 0;
    virtual message error(category, level = level(0)) = 0;
    virtual message critical(category, level = level(0)) = 0;
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_LOGGER__INCLUDED
