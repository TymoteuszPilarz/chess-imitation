//
//  Figure.hpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//

#ifndef Figure_hpp
#define Figure_hpp

#include <vector>
#include "Position.hpp"

class Piece
{
private:
    bool isSelected = false;
    Position position;
    
public:
    Piece(Position pos);
    virtual ~Piece() = 0;
    void SetPosition(Position pos);
    Position GetPosition() const;
    virtual std::vector<Position> GetPossibleMoves() const = 0;
    void Select();
    void Deselect();
    bool IsSelected() const;
    virtual void Render() const = 0;
};

#endif /* Figure_hpp */
