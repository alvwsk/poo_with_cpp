#ifndef AGENDA_HPP
#define AGENDA_HPP

#include "Contact.hpp"
#include "Utils.hpp"
#include <map>

class Agenda
{
private:
    std::map<std::string, Contact> contacts;
public:
    Agenda();
    
    std::string str() const;
    
    std::vector<const Contact*> getFavs() const;

    void addContact(const std::string& name, const std::vector<Fone>& fones);
    void rmFone(const std::string& name, int index);
    void rmContact(const std::string& name);
    std::vector<std::string> search(const std::string& pattern) const;
    void tfav(const std::string& name);
}; 

#endif