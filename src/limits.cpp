#include "limits.hpp"

namespace antiwasm {
    void parseLimitVec(unsigned char* limitVec)
    {
        int nLimits = limitVec[0];
        int pointer = 1;

        for(int i = 0; i < nLimits; i++)
        {
            pointer += getLimits(&limitVec[pointer]);
        }
    }

    int getLimits(unsigned char* limitSection)
    {
        if(limitSection[0] == LIMIT_MIN)
        {
            int *limits = (int*)malloc(sizeof(int) * 2);
            limits[0] = limitSection[1];
            limits[1] = -1;

            std::cout << "Limit[" << limits[0] << "]-[MAX]" << std::endl;

            return 2;
        }
        if(limitSection[0] == LIMIT_MIN_MAX)
        {
            int *limits = (int*)malloc(sizeof(int) * 2);
            limits[0] = limitSection[1];
            limits[1] = limitSection[2];

            std::cout << "Limit[" << limits[0] << "]-[" << limits[1] << "]" << std::endl;

            return 3;
        }
        std::cout << "Error. This byte is not a limit" << std::endl;
        return 1;   //TODO throw an exception
    }

}
