#include "output.hpp"
#include "liblogs/writers/terminal_writer.hpp"
#include <functional>

LIBLOGS_BEGIN_NAMESPACE

output::~output()
{}

void output::initialize(std::vector<std::shared_ptr<writer>> writers)
{
    if (!th_.joinable()) // not started yet
    {
        writers_ = writers;

        if (writers_.empty())
            writers_.push_back(std::make_shared<terminal_writer>());

        run_ = true;
        th_ = std::thread(std::bind(&output::run, this));
    }
}

void output::finalize()
{
    if (th_.joinable())
    {
        run_ = false;
        cv_.notify_all();
        th_.join();
    }
}

void output::write(time_t time, type t, uint64_t category, int level, std::string&& content)
{
    try
    {
        if ((category_mask_ & category) != 0)
        {
            queue_.push({time, t, category, level, std::move(content)});
            cv_.notify_all();
        }
    }
    catch (std::exception const& ex)
    {
        (void)ex;
    }
}

void output::set_max_level(level::value_type level)
{
    max_level_ = level;
}

void output::set_category_mask(category::value_type mask)
{
    category_mask_ = mask;
}

void output::run()
{
    do
    {
        std::unique_lock<std::mutex> lock(m_);
        cv_.wait(lock, [this]{return !run_ || !queue_.empty(); });

        while (!queue_.empty())
        {
            queue_item qi = std::move(queue_.front());
            queue_.pop();

            lock.unlock();

            for (auto const& w: writers_)
                w->write(qi.time, qi.t, qi.category, qi.level, qi.content);

            lock.lock();
        }
    }
    while (run_);
}

LIBLOGS_END_NAMESPACE
