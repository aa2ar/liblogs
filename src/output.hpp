#ifndef LIBLOGS_OUTPUT__INCLUDED
#define LIBLOGS_OUTPUT__INCLUDED

#include "liblogs/logs.hpp"
#include <atomic>
#include <limits>
#include <vector>
#include <queue>
#include <thread>
#include <condition_variable>

LIBLOGS_BEGIN_NAMESPACE

class output
{
public:
    ~output();

    void initialize(std::vector<std::shared_ptr<writer>> writers);
    void finalize();

    void write(time_t time, type type, uint64_t category, int level, std::string&& content);
    int  max_level() const { return max_level_; }
    void set_max_level(level::value_type level);
    void set_category_mask(category::value_type mask);

private:
    struct queue_item
    {
        time_t      time;
        type        t;
        uint64_t    category;
        int         level;
        std::string content;
    };
    std::atomic_int         max_level_{std::numeric_limits<int>::max()};
    uint64_t                category_mask_ = std::numeric_limits<uint64_t>::max();
    std::vector<std::shared_ptr<writer>> writers_;
    std::queue<queue_item>  queue_;
    std::thread             th_;
    std::mutex              m_;
    std::condition_variable cv_;
    std::atomic_bool        run_{false};
    void run();
};

LIBLOGS_END_NAMESPACE

#endif // LIBLOGS_OUTPUT__INCLUDED
