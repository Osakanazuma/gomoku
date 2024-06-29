#include "keyboard.hpp"

// 名前付き定数の定義
constexpr int KEY_W = 119;
constexpr int KEY_S = 115;
constexpr int KEY_A = 97;
constexpr int KEY_D = 100;
constexpr int KEY_SPACE = ' ';

Keyboard::Keyboard(/* args */)
{
    key = 0;
}

Keyboard::~Keyboard()
{
}

bool Keyboard::my_kbhit(void)
{
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    return byteswaiting > 0;
}

void Keyboard::enable_raw_mode(void)
{
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);
}

void Keyboard::disable_raw_mode(void)
{
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(0, TCSANOW, &term);
}

