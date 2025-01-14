#include "Board.h"
#include <iostream>

using namespace std;

int main()
{
    Board board(0, 0);
    while(true) 
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
        else if (cmd == "init") 
        {
            int nPlayers, size;
            ss >> nPlayers >> size;
            board = Board(nPlayers, size);
        } 
        else if (cmd == "addTrap") 
        {
            int pos;
            ss >> pos;
            board.addTrap(pos);
        } 
        else if (cmd == "roll") 
        {
            int value;
            ss >> value;
            board.rollDice(value);
        } 
        else if (cmd == "show") 
        {
            cout << board.str() << endl;
        } 
        else 
        {
            cout << "fail: command not found" << endl;
        }
        }
}