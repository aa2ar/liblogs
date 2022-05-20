#include "liblogs/control.hpp"

LIBLOGS_BEGIN_NAMESPACE

control::control()
    : category_mask_(category::all().value)
    , max_level_(level::max().value)
{

}

void control::set_max_level(level lvl)
{
    max_level_ = lvl.value;
}

level control::max_level() const
{
    return level(max_level_);
}

void control::set_category_mask(category::value_type mask)
{
    category_mask_ = mask;
}

category::value_type control::category_mask() const
{
    return category_mask_;
}

LIBLOGS_END_NAMESPACE
