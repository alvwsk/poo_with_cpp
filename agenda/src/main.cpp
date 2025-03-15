#include "Agenda.hpp"
#include "Utils.hpp"
#include <iostream>

using namespace std;

int main() 
{
    Agenda agenda;
    while(true) 
    {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        try
        {
            if(cmd == "end") 
            {
                break;
            } 
            else if(cmd == "add") 
            {
                string name;
                ss >> name;
                vector<Fone> fones;
                string token;
                while(ss >> token) 
                {
                    auto [id, number] = decodeFone(token);
                    fones.push_back(Fone(id, number));
                }
                agenda.addContact(name, fones);
            } 
            else if(cmd == "show") 
            {
                cout << agenda.str() << '\n';
            } 
            else if(cmd == "rmFone") 
            {
                string name;
                int index;
                ss >> name >> index;
                agenda.rmFone(name, index);
            } 
            else if(cmd == "rm") 
            {
                string name;
                ss >> name;
                agenda.rmContact(name);
            } 
            else if(cmd == "tfav") 
            {
                string name;
                ss >> name;
                agenda.tfav(name);
            } 
            else if(cmd == "favs") 
            {
                cout << map_join(agenda.getFavs(), [](const Contact* c) { return c->str(); }, "\n") << endl;
            }
            else if(cmd == "search") 
            {
                string pattern;
                ss >> pattern;
                cout << map_join(agenda.search(pattern), [](const string& s){ return s; }, "\n") << '\n';
            } 
            else
            {
                cout << "fail: comando invalido" << endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}