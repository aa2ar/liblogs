// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_INITIALIZER__INCLUDED
#define LIBLOGS_INITIALIZER__INCLUDED

#include "liblogsglobal.hpp"
#include <memory>
#include <vector>

LIBLOGS_BEGIN_NAMESPACE

class writer;

struct initializer
{
    initializer(std::vector<std::shared_ptr<writer>> writers);
    ~initializer();

    void set_max_level(int level);
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_INITIALIZER__INCLUDED
