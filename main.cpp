//
//  main.cpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//

#include "Window.hpp"

int main(int argc, const char * argv[])
{
    Window* window = new Window();
    
    while (window->NextTurn());
    
    delete window;
}
