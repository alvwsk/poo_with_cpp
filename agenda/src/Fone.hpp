#ifndef FONE_HPP
#define FONE_HPP

#include <stdexcept>
#include <string>
#include <algorithm>

class Fone
{
private:
    std::string id;
    std::string number;
    static const std::string VALID_CHARS;
public:
    Fone(const std::string& id, const std::string& number);
    std::string str() const;

    std::string getId() const;
    std::string getNumber() const;
private:
    bool isValidNumber(const std::string& number) const;
};

#endif