//
//  Position.hpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//

#ifndef Position_hpp
#define Position_hpp

struct Position
{
    int x = -1;
    int y = -1;
    
    bool IsEmpty() const
    {
        if (x == -1 && y == -1)
        {
            return true;
        }
        
        return false;
    }
    
    void Clear()
    {
        x = y = -1;
    }
    
    bool operator==(const Position& pos) const
    {
        return (x == pos.x && y == pos.y) ? true : false;
    }
};

#endif /* Position_hpp */
