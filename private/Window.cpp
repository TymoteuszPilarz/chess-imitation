//
//  Window.cpp
//  Szachy
//
//  Created by Tymoteusz Pilarz on 16/12/2021.
//

#include <iostream>
#include <algorithm>
#include "Window.hpp"
#include "FrameBuffer.hpp"
#include "Piece.hpp"

bool Window::SelectPiece()
{
    int x, y;
    x = y = 0;
    
    std::cout << "Wybierz figure.\n";
    std::cout << "X: ";
    std::cin >> x;
    if (std::cin.fail() || x < 1 || x > 8)
    {
        std::cin.clear();
        while(std::cin.get() != '\n');
        std::cout << "X: ";
        
        return false;
    }
    
    std::cout << "Y: ";
    std::cin >> y;
    if (std::cin.fail() || y < 1 || y > 8)
    {
        std::cin.clear();
        while(std::cin.get() != '\n');
        std::cout << "Y: ";
        
        return false;
    }
    
    x -= 1;
    y -= 1;
    
    if (board->IsEmpty(Position{x, y}))
    {
        return false;
    }
     
    board->fields[x][y]->Select();
    selectedPos = {x, y};
    possibleMoves = board->fields[x][y]->GetPossibleMoves();
    
    auto newEnd = std::remove_if(possibleMoves.begin(), possibleMoves.end(), [this](const Position& pos){
        return !board->IsEmpty(pos);});

    possibleMoves.erase(newEnd, possibleMoves.end());
    
    return true;
}

bool Window::MovePiece()
{
    int x, y;
    x = y = 0;
    
    std::cout << "Wybierz figure.\n";
    std::cout << "X: ";
    std::cin >> x;
    if (std::cin.fail() || x < 1 || x > 8)
    {
        std::cin.clear();
        while(std::cin.get() != '\n');
        std::cout << "X: ";
        
        return false;
    }
    
    std::cout << "Y: ";
    std::cin >> y;
    if (std::cin.fail() || y < 1 || y > 8)
    {
        std::cin.clear();
        while(std::cin.get() != '\n');
        std::cout << "Y: ";
        
        return false;
    }
    
    x -= 1;
    y -= 1;
    
    Position destination{x, y};
    
    if (std::find(possibleMoves.begin(), possibleMoves.end(), destination) != possibleMoves.end())
    {
        board->fields[selectedPos.x][selectedPos.y]->Deselect();
        board->MovePiece(selectedPos, destination);
        selectedPos.Clear();
        possibleMoves.clear();
        
        return true;
    }
    
    else
    {
        board->fields[selectedPos.x][selectedPos.y]->Deselect();
        selectedPos.Clear();
        possibleMoves.clear();
        
        return false;
    }
}

void Window::UpdateWindow()
{
    system("clear");
    FrameBuffer& buff = FrameBuffer::getBuffer();

    board->Render();

    for (auto& x : board->fields)
    {
        for (auto& y : x)
        {
            if (y != nullptr)
            {
                y->Render();
            }
        }
    }

    buff.drawFrame(possibleMoves);
}

Window::Window()
{
    board = new Board();
}

Window::~Window()
{
    delete board;
}

bool Window::NextTurn()
{
    UpdateWindow();
    
    if (!latestCheck)
    {
        std::cout << "Nieprawidlowa pozycja.\n";
        latestCheck = true;
    }
    
    if (SelectPiece())
    {
        UpdateWindow();
        
        if (!MovePiece())
        {
            latestCheck = false;
        }
    }
    
    else
    {
        latestCheck = false;
    }
    
    return true;
}
