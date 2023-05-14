//
//  Pawn.hpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//  Implemented by Michał Kuś on 17/12/2021.
//

#ifndef Pawn_hpp
#define Pawn_hpp

#include <vector>
#include "Position.hpp"
#include "Piece.hpp"

class Pawn final : public Piece
{
public:
    Pawn(Position pos);
    virtual ~Pawn() override;
    virtual std::vector<Position> GetPossibleMoves() const override;
    virtual void Render() const override;
};

#endif /* Pawn_hpp */
