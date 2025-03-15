#include "Utils.hpp"

std::pair<std::string, std::string> decodeFone(const std::string& fone) 
{
    std::stringstream ss(fone);
    std::string id, number;
    std::getline(ss, id, ':'); 
    std::getline(ss, number);
    return {id, number};
}