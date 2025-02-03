#ifndef THEATER_H
#define THEATER_H 

#include <iostream>
#include <vector>
#include <sstream> 
#include "Client.h"

template<class CONTAINER, class FUNC>
std::string map_join(const CONTAINER& c, FUNC f, std::string sep) {
    std::stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it == c.begin() ? "" : sep) << f(*it);
    }
    return ss.str();
}

class Theater
{
public:
    Theater(int capacity);
    void cancel(std::string id);
    void reserve(int index, std::string id, int phone);
    std::string str() const;
private:
    std::vector<Client> seats;
    bool verifyIndex(int index) const;
    bool search(std::string name) const;
};

#endif