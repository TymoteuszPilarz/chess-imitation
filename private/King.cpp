//
//  King.cpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//  Implemented by Anna Brożek on 17/12/2021.
//

#include "King.hpp"
#include "FrameBuffer.hpp"

King::King(Position pos) : Piece(pos){}

King::~King(){}

std::vector<Position> King::GetPossibleMoves() const
{
    Position position;
    Position pos = GetPosition();
    std::vector<Position> positions;

    for(int y= -1; y<=1; y++) {
        for(int x= -1; x<=1; x++) {

            if(y ==0 && x ==0) {
                continue;
            }

            position.x = pos.x + x;
            position.y = pos.y + y;

            if((position.x >= 0) && (position.y >= 0) && (position.x < 8) && (position.y<8)) {
                positions.push_back(position);
            }
        }
    }
    
    return positions;
}

void King::Render() const
{
    FrameBuffer& buff = FrameBuffer::getBuffer();
    
    
    if (IsSelected())
    {
        buff.writeToBuffer(GetPosition(), 'K');
    }
    
    else
    {
        buff.writeToBuffer(GetPosition(), 'k');
    }
}
