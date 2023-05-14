//
//  King.hpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//  Implemented by Anna Brożek on 17/12/2021.
//

#ifndef King_hpp
#define King_hpp

#include <vector>
#include "Position.hpp"
#include "Piece.hpp"

class King final : public Piece
{
public:
    King(Position pos);
    virtual ~King() override;
    virtual std::vector<Position> GetPossibleMoves() const override;
    virtual void Render() const override;
};

#endif /* King_hpp */
