#include "../includes/limits.hpp"

namespace antiwasm {
    Limit *parseLimits(const unsigned char *limitSection) {
        if (limitSection[0] == limit_types::limit_min) {
            uint32_t min_ = limitSection[1];
            return parseLimitMin(min_);
        }
        if (limitSection[0] == limit_types::limit_min_max) {
            uint32_t min_ = limitSection[1];
            uint32_t max_ = limitSection[2];
            return parseLimitMinMax(min_, max_);
        } else {
            //TODO better error, ¿maybe get a msg?
            auto *limit = new Limit();
            limit->error = true;
            return limit;
        }
    }

    Limit *parseLimitMin(uint32_t min_) {
        auto *limit = new Limit{limit_min, min_, 0, false};

        BOOST_LOG_TRIVIAL(info) << "[limits] New limit [" << std::hex << limit->min << "-MAX]";
        return limit;
    }

    Limit *parseLimitMinMax(uint32_t min_, uint32_t max_) {
        auto *limit = new Limit{limit_min_max, min_, max_, false};
        limit->error = checkIfLimitIsNotValid(min_, max_);

        BOOST_LOG_TRIVIAL(info) << "[limits] New limit [" << std::hex << limit->min << "-" << std::hex << limit->max
                                << "]";

        return limit;
    }

    bool checkIfLimitIsNotValid(uint32_t min_, uint32_t max_) {
        return min_ > max_;
    }

}
