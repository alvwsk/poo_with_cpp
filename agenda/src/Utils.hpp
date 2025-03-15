#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <sstream>
#include <vector>

template <typename CONTAINER, typename FUNC>
std::string map_join(const CONTAINER& cont, FUNC func, const std::string& sep = " ") 
{
    std::stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) 
    {
        ss << (it == cont.begin() ? "" : sep);
        ss << func(*it);
    }
    return ss.str();
}

std::pair<std::string, std::string> decodeFone(const std::string& fone);

#endif