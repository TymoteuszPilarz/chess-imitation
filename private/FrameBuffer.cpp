//
//  FrameBuffer.cpp
//  Szachy
//
//  Created by Dawid Kowal on 16/12/2021.
//

#include <iostream>
#include "FrameBuffer.hpp"

FrameBuffer& FrameBuffer::getBuffer()
{
    static FrameBuffer buff;
    return buff;
}

FrameBuffer::FrameBuffer()
{

    for (int x = 0; x < 18; x += 1)
    {
        frame.push_back(std::vector<char>());
        for (int y = 0; y < 18; y += 1)
        {
            frame[x].push_back(char(0)); //NUL character
        }
    }
}

void FrameBuffer::drawFrame(std::vector<Position> pMoves)
{

    //Draw possible moves
    for (const auto& it: pMoves)
    {
        frame[it.x * 2 + 2][it.y * 2 + 2] = '#';
    }

    for (int y = 0; y < 18; y++)
    {

        for (int x = 0; x < 18; x++)
        {
            std::cout << frame[x][y];
        }
        std::cout << '\n';
    }
}

bool FrameBuffer::writeToBuffer(Position pos, char symbol)
{


    if (((pos.x >= 0) && (pos.x < 8)) && ((pos.y >= 0) && (pos.y < 8)))
    {
        frame[pos.x * 2 + 2][pos.y * 2 + 2] = symbol;

        return true;
    }
    else return false;
}
