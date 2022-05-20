
// Copyright 2021 Alexander Arefyev
// Distributed under MIT license
// See LICENSE file or http://opensource.org/licenses/MIT

#ifndef LIBLOGS_UNIQUE_LOGGER__INCLUDED
#define LIBLOGS_UNIQUE_LOGGER__INCLUDED

#include "liblogs/logger.hpp"
#include <vector>
#include <memory>

LIBLOGS_BEGIN_NAMESPACE

class output;
class writer;

class unique_logger : public logger
{
public:
    unique_logger();
    unique_logger(std::vector<std::shared_ptr<writer>> writers);
    virtual ~unique_logger();

    void initialize(std::vector<std::shared_ptr<writer>> writers);
    void set_max_level(int level);

    message trace(level = level(0)) override;
    message debug(level = level(0)) override;
    message info(level = level(0)) override;
    message warning(level = level(0)) override;
    message error(level = level(0)) override;
    message critical(level = level(0)) override;

    message trace(category, level = level(0)) override;
    message debug(category, level = level(0)) override;
    message info(category, level = level(0)) override;
    message warning(category, level = level(0)) override;
    message error(category, level = level(0)) override;
    message critical(category, level = level(0)) override;

    void set_max_level(level lvl);
    void set_category_mask(category::value_type mask);

private:
    std::unique_ptr<output> out_;
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_UNIQUE_LOGGER__INCLUDED
