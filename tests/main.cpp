#include "liblogs/logs.hpp"
#include "liblogs/initializer.hpp"
#include "liblogs/formatter.hpp"
#include "liblogs/formatters/terminal_formatter.hpp"
#include "liblogs/formatters/colored_terminal_formatter.hpp"
#include "liblogs/writers/file_writer.hpp"
#include "liblogs/writers/terminal_writer.hpp"
#include "liblogs/loggers/unique_logger.hpp"
#include "liblogs/colors.hpp"

#include <iostream>
#include <thread>
#include <ctime>
#include <iomanip>

namespace logs = LIBLOGS_NAMESPACE;

#define enable_trace 1

#if enable_trace
  #define log_trace(lvl) logs::trace(logs::level(lvl)) << "file: " << __FILE__ << ", line: " << __LINE__ << ": "
#else
  #define log_trace(level) (void)0
#endif

class custom_formatter : public logs::formatter
{
public:
    void format(std::ostream& out, time_t time, logs::type t, int level, std::string const& content) override
    {
        out << std::put_time(std::localtime(&time), "%D %T ")
              << "" << static_cast<unsigned>(t) << " " << level << " " << content;
    }
};

static
std::vector<std::shared_ptr<logs::writer>> create_log_writers()
{
    auto term_fmt = std::make_shared<logs::colored_terminal_formatter>();
    auto term_writer = std::make_shared<logs::terminal_writer>(term_fmt, 3);
    term_fmt->set_type_color(logs::type::trace,    logs::colored_terminal_formatter::gray);
    term_fmt->set_type_color(logs::type::info,     logs::colored_terminal_formatter::cyan);
    term_fmt->set_type_color(logs::type::debug,    logs::colored_terminal_formatter::white);
    term_fmt->set_type_color(logs::type::warning,  logs::colored_terminal_formatter::yellow);
    term_fmt->set_type_color(logs::type::error,    logs::colored_terminal_formatter::red);
    term_fmt->set_type_color(logs::type::critical, logs::colored_terminal_formatter::bold_red);

    term_fmt->set_type_text(logs::type::trace,    "TRACE   ");
    term_fmt->set_type_text(logs::type::info,     "INFO    ");
    term_fmt->set_type_text(logs::type::debug,    "DEBUG   ");
    term_fmt->set_type_text(logs::type::warning,  "WARNING ");
    term_fmt->set_type_text(logs::type::error,    "ERROR   ");
    term_fmt->set_type_text(logs::type::critical, "CRITICAL");

    auto fmt = std::make_shared<custom_formatter>();
    auto f_writer = std::make_shared<logs::file_writer>(fmt);
    f_writer->initialize("./log");

    return {term_writer, f_writer};
}

class Foo
{
    std::shared_ptr<logs::logger> logger_;

public:
    explicit Foo(std::shared_ptr<logs::logger> logger) : logger_(logger) {}
    void foo()
    {
        logger_->info() << "Foo::foo called";
    }
};

int main()
{
    uint8_t caterogy_0 = 64;
    uint8_t caterogy_1 = 1;
    (void)caterogy_1;
    logs::category cat_1 = logs::category::make(caterogy_0);

    uint8_t caterogy_2 = 2;
    logs::category cat_2 = logs::category::make(caterogy_2);

    uint8_t caterogy_3 = 3;
    logs::category cat_3 = logs::category::make(caterogy_3);



    auto log_writers = create_log_writers();

    //logs::initializer logs_init(log_writers);

    logs::initialize(log_writers);
    logs::set_max_level(0);
    logs::set_category_mask(0);

    std::shared_ptr<logs::unique_logger> logger
            = std::make_shared<logs::unique_logger>(std::vector<std::shared_ptr<logs::writer>>{log_writers[0]});
    logger->set_max_level(0);

    std::shared_ptr<logs::unique_logger> logger2
            = std::make_shared<logs::unique_logger>(std::vector<std::shared_ptr<logs::writer>>{log_writers[1]});
    logger2->set_max_level(0);

    log_trace(0) << "XYZ";

    logger->info(cat_1) << "123";
    logger->debug(cat_2) << "abc";
    logger->warning(cat_2) << "456 --> category 2";
    logger->warning(cat_3) << "456 --> category 3";
    logger->error() << "error!!!";
    logger->critical() << "alert!!!";

    logs::info() << "XYZ";

    Foo foo(logger2);
    foo.foo();

    logs::finalize();

    return 0;
}

