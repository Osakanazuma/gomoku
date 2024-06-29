#ifndef SAFETY_HPP
#define SAFETY_HPP

#include <termios.h>
#include <unistd.h>
#include <stdexcept> 

class safety
{
private:
    struct termios tty;
public:
    safety();
    ~safety();
    void reset_terminal_settings();
};

#endif // SAFETY_HPP
