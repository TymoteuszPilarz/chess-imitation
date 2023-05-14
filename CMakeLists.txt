cmake_minimum_required(VERSION 3.24)
project(ChessImitation)

set(CMAKE_CXX_STANDARD 17)

add_executable(ChessImitation main.cpp private/Board.cpp private/FrameBuffer.cpp private/King.cpp private/Knight.cpp private/Pawn.cpp private/Piece.cpp private/Rook.cpp private/Window.cpp)
target_include_directories(ChessImitation PRIVATE public)