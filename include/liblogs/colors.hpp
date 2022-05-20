// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_COLORS__INCLUDED
#define LIBLOGS_COLORS__INCLUDED

#include <string>
#include "liblogsglobal.hpp"

LIBLOGS_BEGIN_NAMESPACE

struct log_color
{
    const char * const value;
    log_color(const char *c);
};

namespace color
{
    extern log_color reset;
    extern log_color none;
    extern log_color black;
    extern log_color gray;
    extern log_color red;
    extern log_color green;
    extern log_color yellow;
    extern log_color blue;
    extern log_color magenta;
    extern log_color cyan;
    extern log_color white;
    extern log_color bold_black;
    extern log_color bold_gray;
    extern log_color bold_red;
    extern log_color bold_green;
    extern log_color bold_yellow;
    extern log_color bold_blue;
    extern log_color bold_magenta;
    extern log_color bold_cyan;
    extern log_color bold_white;
}

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_COLORS__INCLUDED
