#include "read_utils.h"

#include <iostream>
#include <string>

int ReadUtils::tryReadUserNumber(const int min, const int max)
{
    std::string user_input_str;
    std::cin >> user_input_str;

    if (user_input_str.size() > 10) {
        return -1;
    }

    for (size_t i = 0; i < user_input_str.size(); i++) {
        if (!std::isdigit(user_input_str[i])) return -1;
    }

    long temp = std::stol(user_input_str);
    
    if (temp < min || temp > max) {
        return -1;
    }


    return static_cast<int>(temp);
}
