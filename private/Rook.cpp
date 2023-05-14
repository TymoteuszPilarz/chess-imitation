//
//  Rook.cpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//  Implemented by Dominik Dziechciarz on 17/12/2021.
//

#include "Rook.hpp"
#include "FrameBuffer.hpp"

Rook::Rook(Position pos) : Piece(pos){}

Rook::~Rook(){}

std::vector<Position> Rook::GetPossibleMoves() const
{
    Position position = GetPosition();
    
    std::vector<Position> positions;
    for (int i = 0; i < 8; i++) {
        if (i != position.x) {
            positions.push_back(Position{i, position.y});
        }
    }
    for (int a = 0; a < 8; a++) {
        if (a != position.y) {
            positions.push_back(Position{position.x, a});
        }
    }
    
    return positions;
}

void Rook::Render() const
{
    FrameBuffer& buff = FrameBuffer::getBuffer();

    if (IsSelected())
    {
        buff.writeToBuffer(GetPosition(), 'W');
    }

    else
    {
        buff.writeToBuffer(GetPosition(), 'w');
    }
}
