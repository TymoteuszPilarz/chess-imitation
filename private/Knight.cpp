//
//  Knight.cpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//  Implemented by Robert Geworgjan on 17/12/2021.
//

#include "Knight.hpp"
#include "FrameBuffer.hpp"

#include <iostream>

Knight::Knight(Position pos) : Piece(pos){}

Knight::~Knight(){}

std::vector<Position> Knight::GetPossibleMoves() const
{
    std::vector<Position> positions;

    Position position = GetPosition();
    int x = position.x;
    int y = position.y;

    if(x+2<8 && y+1<8){
        positions.push_back(Position{x+2, position.y+1});
        std::cout << 1 << std::endl;
    }
    if(x+1<8 && y+2<8){
        positions.push_back(Position{x+1, position.y+2});
        std::cout << 2 << std::endl;
    }
    if(x-2>=0 && y+1<8){
        positions.push_back(Position{x-2, position.y+1});
        std::cout << 3 << std::endl;
    }
    if(x-1>=0 && y+2<8){
        positions.push_back(Position{x-1, position.y+2});
        std::cout << 4 << std::endl;
    }
    if(x+2<8 && y-1>=0){
        positions.push_back(Position{x+2, position.y-1});
        std::cout << 5 << std::endl;
    }
    if(x+1<8 && y-2>=0){
        positions.push_back(Position{x+1, position.y-2});
        std::cout << 6 << std::endl;
    }
    if(x-2>=0 && y-1>=0){
        positions.push_back(Position{x-2, position.y-1});
        std::cout << 7 << std::endl;
    }
    if(x-1>=0 && y-2>=0){
        positions.push_back(Position{x-1, position.y-2});
        std::cout << 8 << std::endl;
    }

    //Wyszukuje dostepne pola i zwraca je jako tablia pozycji
    
    return positions;
}

void Knight::Render() const
{
    FrameBuffer& buff = FrameBuffer::getBuffer();

    if (IsSelected())
    {
        buff.writeToBuffer(GetPosition(), 'S');
    }
    
    else
    {
        buff.writeToBuffer(GetPosition(), 's');
    }
}
