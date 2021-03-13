#include "../includes/limits.hpp"

namespace antiwasm {
    bool parseLimitVec(unsigned char *limitVec) {
        int nLimits = limitVec[0];
        int pointer = 1;

        for (auto i = 0; i < nLimits; i++) {
            int limitFeedback = parseLimits(&limitVec[pointer]);
            if (limitFeedback == -1) {
                return false;
            }
            pointer += limitFeedback;
        }
        return true;
    }

    int parseLimits(const unsigned char *limitSection) {
        if (limitSection[0] == LIMIT_MIN) {
            int limitMin = limitSection[1];
            //limit max is MAX value

            BOOST_LOG_TRIVIAL(debug) << "[limits] Limit[" << limitMin << "]-[MAX]";

            return CODE_LIMIT_MIN;
        }
        if (limitSection[0] == LIMIT_MIN_MAX) {
            int limitMin = limitSection[1];
            int limitMax = limitSection[2];

            BOOST_LOG_TRIVIAL(debug) << "[limits] Limit[" << limitMin << "]-[" << limitMax << "]";

            return CODE_LIMIT_MIN_MAX;
        }
        BOOST_LOG_TRIVIAL(error) << "[limits] These bytes are not a limit";
        return -1;   //TODO throw an exception
    }

}
