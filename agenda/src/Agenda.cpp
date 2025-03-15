#include "Agenda.hpp"

Agenda::Agenda() = default;

std::string Agenda::str() const
{
    return map_join(contacts, [](const auto& pair) { return pair.second.str(); }, "\n");
}

std::vector<const Contact*> Agenda::getFavs() const
{
    std::vector<const Contact*> favs;
    for (const auto& [name, contact] : contacts) 
    {
        if (contact.isFavorited()) 
        {
            favs.push_back(&contact);
        }
    }

    return favs;
}

void Agenda::addContact(const std::string& name, const std::vector<Fone>& fones)
{
    if (contacts.find(name) == contacts.end()) 
    {
        contacts[name] = Contact(name);
    }

    auto& contact = contacts[name];
    for (const auto& fone : fones) 
    {
        contact.addFone(fone.getId(), fone.getNumber());
    }
}

void Agenda::rmFone(const std::string& name, int index)
{
    auto it = contacts.find(name);
    if (it == contacts.end()) 
    {
        throw std::out_of_range("fail: contact not found: " + name);
    }
    it->second.rmFone(index);
}

void Agenda::rmContact(const std::string& name)
{
    auto it = contacts.find(name);
    if (it == contacts.end()) 
    {
        throw std::out_of_range("fail: contact not found: " + name);
    }
    contacts.erase(it);
}

// Busca contatos que correspondem a um padrão
std::vector<std::string> Agenda::search(const std::string& pattern) const
{
    std::vector<std::string> result;
    for (const auto& [name, contact] : contacts) 
    {
        bool match = false;
        if (name.find(pattern) != std::string::npos) 
        {
            match = true;
        } 
        else 
        {
            for (const auto& fone : contact.getFones()) 
            {
                if (fone.getNumber().find(pattern) != std::string::npos) 
                {
                    match = true;
                    break;
                }
            }
        }
        if (match) 
        {
            result.push_back(contact.str());
        }
    }

    return result;
}

void Agenda::tfav(const std::string& name)
{
    auto it = contacts.find(name);
    if (it == contacts.end()) {
        throw std::out_of_range("fail: contact not found: " + name);
    }
    it->second.toggleFavorited();
}