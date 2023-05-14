//
//  Rook.hpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//  Implemented by Dominik Dziechciarz on 17/12/2021.
//

#ifndef Rook_hpp
#define Rook_hpp

#include <vector>
#include "Position.hpp"
#include "Piece.hpp"

class Rook final : public Piece
{
public:
    Rook(Position pos);
    virtual ~Rook() override;
    virtual std::vector<Position> GetPossibleMoves() const override;
    virtual void Render() const override;
};

#endif /* Rook_hpp */
