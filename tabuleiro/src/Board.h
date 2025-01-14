#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <memory>

// Classe que representa o tabuleiro no jogo
class Board 
{
private:
    std::vector<int> trapList;                      // Lista de posições com armadilhas
    std::vector<std::shared_ptr<Player>> players;   // Lista de jogadores
    bool running;                                   // Status do jogo
    int boardSize;                                  // Tamanho do tabuleiro
    int currentPlayer = 0;                          // Índice do jogador atual

    // Método auxiliar para verificar se uma posição é armadilha
    bool isTrap(int position) const;

public:
    // Construtor
    Board(int nPlayers, int boardSize);

    // Adiciona uma armadilha no tabuleiro
    void addTrap(int pos);

    // Joga o dado para o jogador atual
    void rollDice(int value);

    // Representação do tabuleiro como string
    std::string str() const;
};

#endif
