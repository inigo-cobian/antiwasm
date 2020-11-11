#include "limits.hpp"

namespace antiwasm {
    int* getLimits(unsigned char* limitSection)
    {
        if(limitSection[0] == LIMIT_MIN)
        {
            int *limitsToReturn = (int*)malloc(sizeof(int) * 2);
            limitsToReturn[0] = limitSection[1];
            limitsToReturn[1] = -1;

            std::cout << "Limit[" << limitsToReturn[0] << "]-[MAX]" << std::endl;

            return limitsToReturn;
        }
        if(limitSection[0] == LIMIT_MIN_MAX)
        {
            int *limitsToReturn = (int*)malloc(sizeof(int) * 2);
            limitsToReturn[0] = limitSection[1];
            limitsToReturn[1] = limitSection[2];

            std::cout << "Limit[" << limitsToReturn[0] << "]-[" << limitsToReturn[0] << "]" << std::endl;

            return limitsToReturn;
        }
        std::cout << "Error. This byte is not a limit" << std::endl;
        return nullptr;
    }

}
