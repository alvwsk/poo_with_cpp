#include "Theater.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() 
{
    Theater th(0);

    while (true) 
    {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") 
        {
            break;    
        } 
        else if (cmd == "show") 
        {
            std::cout << th.str() << std::endl;
        } 
        else if (cmd == "init") 
        {
            int qtd;
            ss >> qtd;
            th = Theater(qtd);
        } 
        else if (cmd == "reserve") 
        {
            string id;
            int phone;
            int index;
            ss >> id >> phone >> index;
            th.reserve(index, id, phone);
        } 
        else if (cmd == "cancel") 
        {
            string id;
            ss >> id;
            th.cancel(id);
        } 
        else 
        {
            cout << "fail: comando invalido" << endl;
        }
    }
}