#include "../includes/limits.hpp"

namespace antiwasm {
    Limit *parseLimits(const unsigned char *limitSection) { //TODO redefine
        if (limitSection[0] == limit_types::limit_min) {
            int limitMin = limitSection[1];
            //limit max is MAX value

            BOOST_LOG_TRIVIAL(debug) << "[limits] Limit[" << limitMin << "]-[MAX]";

            return new Limit();
        }
        if (limitSection[0] == limit_types::limit_min_max) {
            int limitMin = limitSection[1];
            int limitMax = limitSection[2];

            BOOST_LOG_TRIVIAL(debug) << "[limits] Limit[" << limitMin << "]-[" << limitMax << "]";

            return new Limit();
        }
        BOOST_LOG_TRIVIAL(error) << "[limits] These bytes are not a limit";
        return new Limit();;   //TODO throw an exception
    }

    void parseLimitMin() { }

    void parseLimitMinMax() { }

}
