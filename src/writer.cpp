#include "liblogs/writer.hpp"
#include "liblogs/formatter.hpp"

LIBLOGS_BEGIN_NAMESPACE

writer::writer(std::shared_ptr<formatter> formatter, category::value_type category_mask)
    : formatter_(formatter)
{}

LIBLOGS_END_NAMESPACE

