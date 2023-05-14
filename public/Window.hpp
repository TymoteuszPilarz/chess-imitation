//
//  Window.hpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//

#ifndef Window_hpp
#define Window_hpp

#include <vector>
#include "Position.hpp"
#include "Board.hpp"

class Window
{
private:
    Board* board = nullptr;
    Position selectedPos;
    std::vector<Position> possibleMoves;
    bool latestCheck = true;
    
    bool SelectPiece();
    bool MovePiece();
    void UpdateWindow();
    
public:
    Window();
    ~Window();
    bool NextTurn();
};

#endif /* Window_hpp */
