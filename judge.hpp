//judge.hpp
#ifndef JUDGE_HPP
#define JUDGE_HPP

#include <iostream>
#include "gomoku.hpp"

class Judge {
private:
    Gomoku gomokuGame;
    int win_point;
    int draw_point;

public:
    Judge();
    bool draw_judge(int m_masu[Y_NUMBER][X_NUMBER]);
    bool win_judge(int player, int m_masu[Y_NUMBER][X_NUMBER]);
};

#endif // JUDGE_HPP