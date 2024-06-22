#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <iostream>
#include <vector>
#include <string>

enum GameMode
{
    DEBUG,
    EASY,
    NORMAL,
    HARD
};
enum GameState
{
    MAIN_MENU,
    RUNNING,
    WON,
    LOST
};

struct Field
{
    bool hasMine, hasFlag, isRevealed;
};

class Board
{
private:
    int width, height;
    Field board[100][100];
    GameState gameState;
    GameMode gameMode;
    int revealedCount;
    void placeMinesRandomly();

public:
    Board();
    Board(int width, int height, GameMode mode);
    int getWidth() const;
    int getHeight() const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    bool isRevealed(int row, int col) const;
    GameMode getGameMode() const;
    void setGameMode(GameMode mode);
    GameState getGameState() const;
    void setGameState(GameState state);
    char getFieldInfo(int row, int col) const;
    void reset();
};

#endif // BOARD_H