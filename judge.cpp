//judge.cpp
#include "judge.hpp"

Judge::Judge()
{
    win_point = 0;
    draw_point = 0;
}

bool Judge::win_judge(int player, int m_masu[Y_NUMBER][X_NUMBER])
    { 
        win_point = 0;

    for (int i = 0; i < Y_NUMBER; i++)
    {
        win_point = 0;
        for (int j = 0; j < X_NUMBER; j++) {
            if (m_masu[i][j] == player) 
            {
                win_point++;
                if (win_point == 5) 
                {
                    std::cout << "player " << player << " wins" << std::endl;
                    return true;
                }
            } 
            else
            {
                win_point = 0;
            }
        }
    }

    for (int i = 0; i < X_NUMBER; i++)
    {
        win_point = 0;
        for (int j = 0; j < Y_NUMBER; j++) 
        {
            if (m_masu[j][i] == player) 
            {
                win_point++;
                if (win_point == 5) 
                {
                    std::cout << "player " << player << " wins" << std::endl;
                    return true;
                }
            } 
            else 
            {
                win_point = 0;
            }
        }
    }

        for (int col = 0; col < X_NUMBER; col++)
        {  
            for (int line = 0; line < Y_NUMBER; line++)
            {
                win_point = 0; // 対角線（右上から左下）のチェック前にリセット
                for (int i = 0; i < 5; i++) // 5つの連続したマスをチェック
                {
                    if (col + i < X_NUMBER && line + i < Y_NUMBER && m_masu[col + i][line + i] == player)
                    {
                        win_point++;
                        if (win_point == 5)
                        {
                            std::cout << "player " << player << " wins" << std::endl;
                            return true;
                        }
                    }
                    else
                    {
                        win_point = 0;
                    }
                }
                win_point = 0; // 対角線（左上から右下）のチェック前にリセット
                for (int i = 0; i < 5; i++) // 5つの連続したマスをチェック
                {
                    if (col + i < X_NUMBER && line - i >= 0 && m_masu[col + i][line - i] == player)
                    {
                        win_point++;
                        if (win_point == 5)
                        {
                            std::cout << "player " << player << " wins" << std::endl;
                            return true;
                        }
                    }
                    else
                    {
                        win_point = 0;
                    }
                }  
            }
        }
        
    return false;
}

bool Judge::draw_judge(int m_masu[Y_NUMBER][X_NUMBER])
{
    draw_point = 0;
    for (int i = 0; i < Y_NUMBER; i++)
    {
        for (int j = 0; j < X_NUMBER; j++)
        {
            if (m_masu[i][j] != 0)
            {
                draw_point++;
            }
        }
    }
    if (draw_point == Y_NUMBER * X_NUMBER)
    {
        std::cout << "draw" << std::endl;
        return true;
    }
    return false; // Add a return statement for the case when the condition is not met.
}
