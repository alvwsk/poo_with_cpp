#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client
{
public:
    Client(std::string id, int phone = -1);

    std::string getId() const;
    int getPhone() const;

    std::string str() const;
    
private:
    std::string id;
    int phone;
};

#endif