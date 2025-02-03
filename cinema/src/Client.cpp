#include "Client.h"

Client::Client(std::string id, int phone) : id(id), phone(phone) {}

std::string Client::getId() const { return id; }
int Client::getPhone() const { return phone; }

std::string Client::str() const 
{
    return (phone == -1) ? id : (id + ":" + std::to_string(phone));
}
