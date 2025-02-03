#include "Theater.h"

Theater::Theater(int capacity) : seats(capacity, Client("-")) {}

void Theater::cancel(std::string id)
{
    for(auto &client : seats)
        if(client.getId() == id)
        {
            client = Client("-");
            return;
        }    

    std::cout << "fail: cliente nao esta no cinema" << std::endl;
}

void Theater::reserve(int index, std::string id, int phone)
{
    if (index < 0 || index >= (int) seats.size()) 
    {
        std::cout << "fail: cadeira nao existe" << std::endl; 
        return;
    }

    if(verifyIndex(index))
    {
        std::cout << "fail: cadeira ja esta ocupada" << std::endl;
        return;
    }

    if(search(id))
    {
        std::cout << "fail: cliente ja esta no cinema"<< std::endl;
        return;
    }
               
    seats[index] = Client(id, phone);
}

std::string Theater::str() const
{
    return "[" + map_join(seats, [](const Client& client){ return client.str(); }, " ") + "]";
}

bool Theater::verifyIndex(int index) const
{
    return seats[index].getId() != "-"; 
}

bool Theater::search(std::string name) const
{
    for(const auto &client : seats)
        if(client.getId() == name)
            return true;
        
    return false;
}
