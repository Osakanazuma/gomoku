#ifndef START_PROGRAM_HPP
#define START_PROGRAM_HPP

#include <iostream> 
#include "judge.hpp"
#include "gomoku.hpp"
#include "keyboard.hpp"
#include "safety.hpp"

struct temp 
{
    int temp_x = 0;
    int temp_y = 0;
};


class StartProgram{
private:
    Gomoku m_gomoku;
    Judge m_judge;
    Keyboard m_keyboard;
    gomoku_p temp;
    safety m_safety;
    
    int player;

public:
    StartProgram();
    void game();
};

#endif // START_PROGRAM_HPP