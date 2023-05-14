//
//  FrameBuffer.hpp
//  Szachy
//
//  Created by Dawid Kowal on 16/12/2021.
//

#ifndef FrameBuffer_hpp
#define FrameBuffer_hpp

#include <vector>
#include "Position.hpp"

class FrameBuffer {
  FrameBuffer();

public:
  static FrameBuffer &getBuffer();
  std::vector<std::vector<char>> frame;


  void drawFrame(std::vector<Position>);
  bool writeToBuffer(Position pos, char symbol);
};

#endif
