//gomoku.cpp
#include "gomoku.hpp"

Gomoku::Gomoku()
{
    m_time = 0;
    for (int i = 0; i < X_NUMBER; i++)
    {
        for (int j = 0; j < Y_NUMBER; j++)
        {
            m_masu[i][j] = 0;
        }
    }
    
    x = 0;
    y = 0;
}

void Gomoku::masume(int time)
{
    
    for(int i = 0; i < X_NUMBER; i++)
    {
        if (i == 0)
        {
            std::cout << " ";
        }
        std::cout << " " << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < X_NUMBER; i++)
    {
        std::cout << i;
        for (int j = 0; j < Y_NUMBER; j++)
        {
            if (gomoku_pb.py == i && gomoku_pb.px == j)
            {
                if (time == 1)
                {
                    std::cout << " ■ ";
                }
                if (time == 2)
                {
                    std::cout << "\033[31m ■ \033[m";
                }
            }
            else
            if (m_masu[i][j] == 0)
            {
                std::cout << " - ";
            }
            else if (m_masu[i][j] == 2)
            {
                std::cout << "\033[31m ● \033[m";
            }
            else if (m_masu[i][j] == 1)
            {
                std::cout << " ● ";
            }

        }
        std::cout << std::endl;
    }
}

gomoku_p Gomoku::move(int key)
{
    if (key == 'w')
    {
        if (y > 0)
        {
            y--;
        }
    }
    else if (key == 's')
    {
        if (y < X_NUMBER - 1)
        {
            y++;
        }
    }
    else if (key == 'a')
    {
        if (x > 0)
        {
            x--;
        }
    }
    else if (key == 'd')
    {
        if (x < Y_NUMBER - 1)
        {
            x++;
        }
    }
    gomoku_pb.px = x;
    gomoku_pb.py = y;

    return gomoku_pb;
}

void Gomoku::dainyuu(int col, int line)
{
    if (m_time % 2 == 1)
    {
        m_masu[col][line] = 2;
    }
    else
    {
        m_masu[col][line] = 1;
    }
    m_time++;
}

// Path: main.cpp   