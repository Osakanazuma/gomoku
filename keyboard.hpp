#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdbool.h>

#include "gomoku.hpp"

class Keyboard
{
private:
    int key;
    Gomoku gomokukey;

public:
    Keyboard(/* args */);
    ~Keyboard();

    bool my_kbhit(void);
    void enable_raw_mode(void);
    void disable_raw_mode(void);

};

#endif // KEYBOARD_HPP
