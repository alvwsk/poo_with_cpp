#include "Board.h"

Board::Board(int nPlayers, int boardSize) : players(nPlayers, nullptr), running(true), boardSize(boardSize)
{
    for (int i = 0; i < nPlayers; i++)
    {
        players[i] = std::make_shared<Player>(i + 1);
    }
}

void Board::addTrap(int pos)
{
    trapList.push_back(pos);
}

bool Board::isTrap(int position) const 
{
    return std::find(trapList.begin(), trapList.end(), position) != trapList.end();
}

void Board::rollDice(int value)
{
    if(!running)
    {
        std::cout << "game is over" << std::endl;
        return;
    }

    auto player = players[currentPlayer];

    if(!player->isFree())
    {
        if(value % 2 == 0)
        {
            std::cout << player->str() << " se libertou" << std::endl;
            player->setFree(true); 
            currentPlayer = (currentPlayer + 1) % players.size();
            return;
        }

        std::cout << player->str() << " continua preso" << std::endl;
        currentPlayer = (currentPlayer + 1) % players.size();
        return;
    }

    int newPosition = player->getPosition() + value;
    if(newPosition > boardSize)
    {
        std::cout << player->str() << " ganhou" << std::endl;
        player->setPosition(std::min(newPosition, boardSize));
        running = false;
        return; 
    }

    player->setPosition(newPosition);
    std::cout << player->str() << " andou para " << newPosition << std::endl;


    if(isTrap(newPosition))
    {
        player->setFree(false);
        std::cout << player->str() << " caiu em uma armadilha" << std::endl;
    }

    currentPlayer = (currentPlayer + 1) % players.size();
}

std::string Board::str() const
{
    std::stringstream ss;

    std::string trapsLine(boardSize + 1, '.');
    for (const auto &trap : trapList) { trapsLine[trap] = 'x'; }

    for (const auto &player : players)
    {
        std::string playerLine(boardSize + 1, '.');
        playerLine[player->getPosition()] = '0' + player->getLabel();
        ss << player->str() << ": " << playerLine << std::endl;
    }

    ss << "traps__: " << trapsLine;

    return ss.str();
}