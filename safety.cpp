#include "safety.hpp"

safety::safety(/* args */)
{
}

safety::~safety()
{
}

void safety::reset_terminal_settings()
{
    if (tcgetattr(STDIN_FILENO, &tty) != 0) 
    {
        throw std::runtime_error("tcgetattr failed");
    }

    tty.c_lflag |= (ECHO | ICANON);

    if (tcsetattr(STDIN_FILENO, TCSANOW, &tty) != 0) 
    {
        throw std::runtime_error("tcsetattr failed");
    }
}