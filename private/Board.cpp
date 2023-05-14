//
//  Board.cpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//

#include <random>
#include "Board.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "FrameBuffer.hpp"

Position Board::GetRandomPosition() const
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> distrib(0, 7);

    int randX = distrib(mt);
    int randY = distrib(mt);

    while (!IsEmpty(Position{randX, randY}))
    {
        randX = distrib(mt);
        randY = distrib(mt);
    }

    return Position{randX, randY};
}

bool Board::IsEmpty(Position pos) const
{
    return fields[pos.x][pos.y] == nullptr;
}

Board::Board()
{
    fields.resize(8, std::vector<Piece*>(8));

    Position randomPos = GetRandomPosition();
    fields[randomPos.x][randomPos.y] = new King(Position{randomPos.x, randomPos.y});

    randomPos = GetRandomPosition();
    fields[randomPos.x][randomPos.y] = new Knight(Position{randomPos.x, randomPos.y});

    randomPos = GetRandomPosition();
    fields[randomPos.x][randomPos.y] = new Pawn(Position{randomPos.x, randomPos.y});

    randomPos = GetRandomPosition();
    fields[randomPos.x][randomPos.y] = new Rook(Position{randomPos.x, randomPos.y});
}

Board::~Board()
{
    for (auto& x: fields)
    {
        for (auto& y: x)
        {
            if (y != nullptr)
            {
                delete y;
            }
        }
    }
}

bool Board::MovePiece(Position srcPos, Position destPos)
{
    if (fields[destPos.x][destPos.y] != nullptr)
        return false;

    fields[srcPos.x][srcPos.y]->SetPosition(destPos);
    fields[destPos.x][destPos.y] = fields[srcPos.x][srcPos.y];
    fields[srcPos.x][srcPos.y] = nullptr;

    return true;
}

void Board::Render() const
{
    FrameBuffer& buff = FrameBuffer::getBuffer();


    //Filling all board fields with spaces
    for (int y = 2; y < 17; y += 2)
    {
        for (int x = 2; x < 17; x += 2)
        {
            buff.frame[x][y] = 32; //(space) in ascii
        }
    }

    buff.frame[0][0] = ' ';

    //Filling in the corners
    buff.frame[1][1] = /*char(201)*/'+';
    buff.frame[17][1] = /*char(187)*/'+';
    buff.frame[1][17] = /*char(200)*/'+';
    buff.frame[17][17] =/* char(188)*/'+';

    //Filling in the horizontal indexes
    for (int i = 1; i <= 17; i++)
    {

        buff.frame[i][0] = i % 2 ? ' ' : (i / 2) + 48;
    }

    //Filling in the top and bottom rows of the buff.frame
    for (int x = 2; x < 17; x++)
    {
        buff.frame[x][1] = x % 2 ? /*205*/'_' : /*209*/'_';
    }

    for (int x = 2; x < 17; x++)
    {
        buff.frame[x][17] = x % 2 ? /*205*/'_' : /*207*/'_';
    }

    //Filling in the vertical indexes
    for (int i = 1; i <= 17; i++)
    {

        buff.frame[0][i] = i % 2 ? ' ' : (i / 2) + 48;
    }

    //Filling left and rightside columns
    for (int y = 2; y < 17; y++)
    {
        buff.frame[1][y] = y % 2 ? /*186*/'|' : /*199*/'|';
    }

    for (int y = 2; y < 17; y++)
    {
        buff.frame[17][y] = y % 2 ? /*186*/'|' : /*182*/'|';
    }


    //Filling in the middle of the buff.frame
    for (int y = 2; y < 17; y += 1)
    {

        if (!(y % 2))
        {

            for (int x = 3; x < 17; x += 2)
            {
                buff.frame[x][y] = '|';
            }
        }
        else
        {

            for (int x = 2; x < 17; x += 1)
            {
                buff.frame[x][y] = x % 2 ? /*196*/'_' : /*197*/'_';
            }
        }
    }
}
