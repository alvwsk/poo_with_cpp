#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <sstream>

// Classe que representa um jogador no jogo
class Player 
{
private:
    int label;        // Identificador único do jogador
    int position;     // Posição atual do jogador no tabuleiro
    bool free;        // Indica se o jogador está livre (não preso em uma armadilha)

public:
    // Construtor que inicializa o jogador com um identificador
    Player(int label);

    // Verifica se o jogador está livre
    bool isFree() const;

    // Define o estado de liberdade do jogador
    void setFree(bool value);

    // Obtém a posição atual do jogador
    int getPosition() const;

    // Define a posição do jogador no tabuleiro
    void setPosition(int value);

    // Obtém o identificador único do jogador
    int getLabel() const;

    // Representação do jogador em string
    std::string str() const;
};

#endif