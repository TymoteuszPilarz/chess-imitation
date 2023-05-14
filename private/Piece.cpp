//
//  Figure.cpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//

#include "Piece.hpp"

Piece::Piece(Position pos) : position(pos){}

Piece::~Piece(){}

void Piece::SetPosition(Position pos)
{
    position = pos;
}

Position Piece::GetPosition() const
{
    return position;
}

void Piece::Select()
{
    isSelected = true;
}

void Piece::Deselect()
{
    isSelected = false;
}

bool Piece::IsSelected() const
{
    return isSelected;
}
