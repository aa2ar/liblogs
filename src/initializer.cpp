#include "liblogs/initializer.hpp"
#include "liblogs/logs.hpp"

LIBLOGS_BEGIN_NAMESPACE

initializer::initializer(std::vector<std::shared_ptr<writer>> writers)
{
    initialize(std::move(writers));
}

initializer::~initializer()
{
    finalize();
}

void initializer::set_max_level(int level)
{
    LIBLOGS_NAMESPACE::set_max_level(level);
}

LIBLOGS_END_NAMESPACE
