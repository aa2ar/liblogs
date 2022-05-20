#include "colors.hpp"
#include "liblogs/colors.hpp"

LIBLOGS_BEGIN_NAMESPACE

const char * const reset_color_str        = "\033[0m";
const char * const black_color_str        = "\033[30m";
const char * const gray_color_str         = "\033[90m";
const char * const red_color_str          = "\033[31m";
const char * const green_color_str        = "\033[92m";
const char * const yellow_color_str       = "\033[93m";
const char * const blue_color_str         = "\033[94m";
const char * const magenta_color_str      = "\033[95m";
const char * const cyan_color_str         = "\033[96m";
const char * const white_color_str        = "\033[97m";
const char * const bold_black_color_str   = "\033[1;30m";
const char * const bold_gray_color_str    = "\033[1;90m";
const char * const bold_red_color_str     = "\033[1;31m";
const char * const bold_green_color_str   = "\033[1;92m";
const char * const bold_yellow_color_str  = "\033[1;93m";
const char * const bold_blue_color_str    = "\033[1;94m";
const char * const bold_magenta_color_str = "\033[1;95m";
const char * const bold_cyan_color_str    = "\033[1;96m";
const char * const bold_white_color_str   = "\033[1;97m";

log_color::log_color(const char *c) : value(c) {}

namespace color
{
    LIBLOGS_NAMESPACE::log_color reset(reset_color_str);
    LIBLOGS_NAMESPACE::log_color none(reset_color_str);
    LIBLOGS_NAMESPACE::log_color black(black_color_str);
    LIBLOGS_NAMESPACE::log_color gray(gray_color_str);
    LIBLOGS_NAMESPACE::log_color red(red_color_str);
    LIBLOGS_NAMESPACE::log_color green(green_color_str);
    LIBLOGS_NAMESPACE::log_color yellow(yellow_color_str);
    LIBLOGS_NAMESPACE::log_color blue(blue_color_str);
    LIBLOGS_NAMESPACE::log_color magenta(magenta_color_str);
    LIBLOGS_NAMESPACE::log_color cyan(cyan_color_str);
    LIBLOGS_NAMESPACE::log_color white(white_color_str);
    LIBLOGS_NAMESPACE::log_color bold_black(bold_black_color_str);
    LIBLOGS_NAMESPACE::log_color bold_gray(bold_gray_color_str);
    LIBLOGS_NAMESPACE::log_color bold_red(bold_red_color_str);
    LIBLOGS_NAMESPACE::log_color bold_green(bold_green_color_str);
    LIBLOGS_NAMESPACE::log_color bold_yellow(bold_yellow_color_str);
    LIBLOGS_NAMESPACE::log_color bold_blue(bold_blue_color_str);
    LIBLOGS_NAMESPACE::log_color bold_magenta(bold_magenta_color_str);
    LIBLOGS_NAMESPACE::log_color bold_cyan(bold_cyan_color_str);
    LIBLOGS_NAMESPACE::log_color bold_white(bold_white_color_str);
}

LIBLOGS_END_NAMESPACE
