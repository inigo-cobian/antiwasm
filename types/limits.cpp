#include "limits.hpp"

namespace antiwasm {
    Limit parseLimits(const uint8_t *limitSection) {
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
            Limit limit{};
            limit.error = true;
            return limit;
        }
    }

    Limit parseLimitMin(const uint32_t min_) {
        Limit limit{limit_min, min_, 0, false};

        BOOST_LOG_TRIVIAL(info) << "[limits] New limit ["
                                << std::hex << limit.min << "-MAX]";
        return limit;
    }

    Limit parseLimitMinMax(const uint32_t min_, const uint32_t max_) {
        Limit limit{limit_min_max, min_, max_, false};
        limit.error = checkIfLimitIsNotValid(min_, max_);

        BOOST_LOG_TRIVIAL(info) << "[limits] New limit ["
                                << std::hex << limit.min << "-"
                                << std::hex << limit.max
                                << "]";

        return limit;
    }

    bool checkIfLimitIsNotValid(const uint32_t min_, const uint32_t max_) {
        return min_ > max_;
    }

}
