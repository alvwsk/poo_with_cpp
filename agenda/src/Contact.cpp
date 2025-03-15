#include "Contact.hpp"
#include "Utils.hpp"

Contact::Contact(const std::string& name) : favorited(false), fones(), name(name) {}

std::string Contact::str() const
{
    std::stringstream ss;
    ss << (favorited? "@ " : "- ") << name << " [" 
    << map_join(fones, [](const Fone& fone){ return fone.str(); }, ", ") << "]";

    return ss.str();
}

void Contact::toggleFavorited() 
{ 
    favorited = !favorited; 
}

bool Contact::isFavorited() const 
{ 
    return favorited; 
}
    
void Contact::addFone(const std::string& id, const std::string& number)
{
    fones.push_back(Fone(id, number));
}

void Contact::rmFone(int index)
{
    if(index < 0 || index >= fones.size())
    {
        throw std::out_of_range("fail: invalid index");
    }

    fones.erase(fones.begin() + index);
}

std::vector<Fone> Contact::getFones() const 
{
    return fones;
}