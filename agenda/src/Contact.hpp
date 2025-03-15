#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Fone.hpp"
#include <vector>
#include <sstream>

class Contact
{
private:
    bool favorited;
    std::vector<Fone> fones;
    std::string name;
public:
    Contact(const std::string& name = "");

    std::string str() const;

    void toggleFavorited();
    bool isFavorited() const;
    void addFone(const std::string& id, const std::string& number);
    void rmFone(int index);
    std::vector<Fone> getFones() const;
};

#endif