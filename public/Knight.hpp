//
//  Knight.hpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//  Implemented by Robert Geworgjan on 17/12/2021.
//

#ifndef Knight_hpp
#define Knight_hpp

#include <vector>
#include "Position.hpp"
#include "Piece.hpp"

class Knight final : public Piece
{
public:
    Knight(Position pos);
    virtual ~Knight() override;
    virtual std::vector<Position> GetPossibleMoves() const override;
    virtual void Render() const override;
};

#endif /* Knight_hpp */
