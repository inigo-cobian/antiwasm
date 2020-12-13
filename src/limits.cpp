#include "../includes/limits.hpp"

namespace antiwasm {
    bool parseLimitVec(unsigned char* limitVec)
    {
        int nLimits = limitVec[0];
        int pointer = 1;

        for(auto i = 0; i < nLimits; i++)
        {
            pointer += getLimits(&limitVec[pointer]);
            //TODO is bad return false
        }
        return true;
    }

    int getLimits(const unsigned char* limitSection)
    {
        if(limitSection[0] == LIMIT_MIN)
        {
            auto limitMin = limitSection[1];
            //limit max is MAX value

            BOOST_LOG_TRIVIAL(debug) << "Limit[" << limitMin << "]-[MAX]";

            return 2;
        }
        if(limitSection[0] == LIMIT_MIN_MAX)
        {
            auto limitMin = limitSection[1];
            auto limitMax = limitSection[2];

            BOOST_LOG_TRIVIAL(debug) << "Limit[" << limitMin << "]-[" << limitMax << "]";

            return 3;
        }
        BOOST_LOG_TRIVIAL(error) << "These bytes are not a limit";
        return -1;   //TODO throw an exception
    }

}
