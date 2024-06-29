//gomoku.hpp
#ifndef GOMOKU_HPP
#define GOMOKU_HPP

#include <iostream>

#define X_NUMBER 10  //行
#define Y_NUMBER 10  //列

struct gomoku_p
{
    int px = 0;
    int py = 0;
};


class Gomoku{
private:

    int m_time;
    gomoku_p gomoku_pb;
    int x = 0, y = 0;   
public:
    int m_masu[Y_NUMBER][X_NUMBER] = {{0}};
    int m_return[2];
    Gomoku();
    void masume(int time);
    gomoku_p move(int key);
    void dainyuu(int col, int line);
};

#endif // GOMOKU_HPP


