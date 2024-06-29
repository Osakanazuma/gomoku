#include "start_program.hpp"

StartProgram::StartProgram() : player(1)
{
}

void StartProgram::game()
{ 
    system("clear"); // ここで画面をクリア
    m_gomoku.masume(player);
    while (true)
    {
        std::cout << "player" << player << "の番です" << std::endl;
        m_keyboard.enable_raw_mode();
        while (true)
        {
            if (m_keyboard.my_kbhit())
            {
                int key = getchar();
                if (key == 'w' || key == 's' || key == 'a' || key == 'd')
                {
                    temp = m_gomoku.move(key);
                    system("clear"); // ユーザーがキーを押すたびに画面をクリア
                    m_gomoku.masume(player);
                }
                else if (key == ' ' || key == '\n') // ここを変更: enterキーを追加
                {
                    if (m_gomoku.m_masu[temp.py][temp.px] == 0)
                    {
                        break;
                    }
                }
            }
        }
        
        m_gomoku.dainyuu(temp.py, temp.px);
        system("clear"); // 盤面が更新されるたびに画面をクリア
        m_gomoku.masume(player);
        if( m_judge.win_judge(player,m_gomoku.m_masu)|| m_judge.draw_judge(m_gomoku.m_masu))
        {
            system("stty sane");
            break;
        }
        player = (player == 1) ? 2 : 1;
    }
    m_gomoku.masume(player);
}