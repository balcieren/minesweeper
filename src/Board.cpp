#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <math.h>

Board::Board() : width(10), height(10), gameState(MAIN_MENU), gameMode(DEBUG)
{
    placeMinesRandomly();
}

Board::Board(int width, int height, GameMode mode) : width(width), height(height), gameState(RUNNING), gameMode(mode)
{
    placeMinesRandomly();
}

int Board::getWidth() const
{
    return width;
}

int Board::getHeight() const
{
    return height;
}

int Board::countMines(int row, int col) const
{
    int mineCount = 0;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && board[newRow][newCol].hasMine)
            {
                ++mineCount;
            }
        }
    }
    return mineCount;
}

bool Board::hasFlag(int row, int col) const
{
    return board[row][col].hasFlag;
}

void Board::toggleFlag(int row, int col)
{
    if (!board[row][col].isRevealed)
    {
        board[row][col].hasFlag = !board[row][col].hasFlag;
    }
}

void Board::revealField(int row, int col)
{
reReveal:

    if (row < 0 || row >= height || col < 0 || col >= width || board[row][col].isRevealed || board[row][col].hasFlag)
    {
        return;
    }

    board[row][col].isRevealed = true;

    if (board[row][col].hasMine)
    {
        if (revealedCount == 0)
        {
            reset();
            goto reReveal;
        }
        else
        {
            gameState = LOST;
        }
    }
    else
    {
        ++revealedCount;
        int mineCount = countMines(row, col);
        if (mineCount == 0)
        {
            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    // According to the original game, flags also open.
                    if (row + i >= 0 && col + j >= 0 && board[row + i][col + j].hasFlag)
                        board[row + i][col + j].hasFlag = false;

                    revealField(row + i, col + j);
                }
            }
        }
    }

    bool allFieldsRevealed = true;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (!board[i][j].isRevealed && !board[i][j].hasMine)
            {
                allFieldsRevealed = false;
                break;
            }
        }
    }
    if (allFieldsRevealed)
    {
        gameState = WON;
    }
}

bool Board::isRevealed(int row, int col) const
{
    return board[row][col].isRevealed;
}

GameMode Board::getGameMode() const
{
    return GameMode();
}

void Board::setGameMode(GameMode mode)
{
    this->gameMode = mode;
}

GameState Board::getGameState() const
{
    return gameState;
}

void Board::setGameState(GameState state)
{
    this->gameState = state;
}

char Board::getFieldInfo(int row, int col) const
{
    if (board[row][col].isRevealed)
    {
        if (board[row][col].hasMine)
        {
            return '*';
        }

        int mineCount = countMines(row, col);
        return mineCount == 0 ? '0' : '0' + mineCount;
    }
    else
    {
        return board[row][col].hasFlag ? 'F' : ' ';
    }
}

void Board::reset()
{
    placeMinesRandomly();
}

void Board::placeMinesRandomly()
{
    std::srand(std::time(nullptr));

    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            board[w][h] = {false, false, false};
        }
    }

    int minesToPlace = 0;
    switch (gameMode)
    {
    case DEBUG: // 10 mines
        minesToPlace = 10;
        break;
    case EASY: // 10% of the board
        minesToPlace = round((width * height * 10) / 100);
        break;
    case NORMAL: // 20% of the board
        minesToPlace = round((width * height * 20) / 100);
        break;
    case HARD: // 30% of the board
        minesToPlace = round((width * height * 30) / 100);
        break;
    }

    while (minesToPlace > 0)
    {
        int row = std::rand() % height;
        int col = std::rand() % width;
        if (!board[row][col].hasMine)
        {
            board[row][col].hasMine = true;
            --minesToPlace;
        }
    }
}
