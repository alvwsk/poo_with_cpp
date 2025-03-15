#include "Fone.hpp"

const std::string Fone::VALID_CHARS = "().";

Fone::Fone(const std::string& id, const std::string& number)
{
    if (!isValidNumber(number)) {
        throw std::invalid_argument("fail: invalid number");
    }
    this->id = id;
    this->number = number;
}

std::string Fone::str() const
{
    return id + ":" + number;
}

std::string Fone::getId() const
{
    return id;
}

std::string Fone::getNumber() const
{
    return number;
}

bool Fone::isValidNumber(const std::string& number) const
{
    return std::all_of(number.begin(), number.end(), [](char c) 
    {
        return std::isdigit(c) || Fone::VALID_CHARS.find(c) != std::string::npos;
    });
}