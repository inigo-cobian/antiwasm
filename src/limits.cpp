#include "../includes/limits.hpp"

namespace antiwasm {
    Limit *parseLimits(const unsigned char *limitSection) {
        if (limitSection[0] == limit_types::limit_min) {
            return parseLimitMin(limitSection[1]);
        }
        else if (limitSection[0] == limit_types::limit_min_max) {
            return parseLimitMinMax(limitSection[1], limitSection[2]);
        }
        else {
            //TODO better error, ¿maybe get a msg?
            Limit *limit = new Limit();
            limit->error = true;
            return limit;
        }
    }

    Limit *parseLimitMin(uint32_t min_) {
        auto *limit = new Limit();
        limit->type = limit_min;
        limit->min = min_;

        BOOST_LOG_TRIVIAL(info) << "[limits] New limit [" << std::hex << limit->min << "-MAX]";
    }

    Limit *parseLimitMinMax(uint32_t min_, uint32_t max_) {
        auto *limit = new Limit();
        limit->type = limit_min_max;
        limit->min = min_;
        limit->max = max_;
        limit->error = checkIfLimitIsNotValid(min_, max_);

        BOOST_LOG_TRIVIAL(info) << "[limits] New limit [" << std::hex << limit->min << "-" << std::hex << limit->max << "]";
    }

    bool checkIfLimitIsNotValid(uint32_t min_, uint32_t max_) {
        return min_ > max_;
    }

}
