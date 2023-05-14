//
//  Board.hpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//

#ifndef Board_hpp
#define Board_hpp

#include <vector>
#include "Position.hpp"
#include "Piece.hpp"

class Board
{
private:
    Position GetRandomPosition() const;
    
public:
    std::vector<std::vector<Piece*>> fields;
    
    Board();
    ~Board();
    bool MovePiece(Position srcPos, Position destPos);
    bool IsEmpty(Position pos) const;
    void Render() const;
};

#endif /* Board_hpp */
