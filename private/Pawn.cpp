//
//  Pawn.cpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//  Implemented by Michał Kuś on 17/12/2021.
//

#include "Pawn.hpp"
#include "FrameBuffer.hpp"

Pawn::Pawn(Position pos) : Piece(pos){}

Pawn::~Pawn(){}

std::vector<Position> Pawn::GetPossibleMoves() const
{
    Position position = GetPosition();
    int x = position.x;
    int y = position.y;

    std::vector<Position> arrayOfPositions;

    if(y == 0){
      arrayOfPositions.push_back(Position{x,7});
    } else {
      arrayOfPositions.push_back(Position{x,y-1});
    }

    return arrayOfPositions;
}

void Pawn::Render() const
{
    FrameBuffer& buff = FrameBuffer::getBuffer();

    if (IsSelected())
    {
        buff.writeToBuffer(GetPosition(), 'P');
    }
    
    else
    {
        buff.writeToBuffer(GetPosition(), 'p');
    }
}
