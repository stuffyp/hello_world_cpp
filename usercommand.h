#ifndef USER_COMMAND_H
#define USER_COMMAND_H

#include <iostream>

enum class UserCommand
{
    Up,
    Down,
    Left,
    Right,
    Quit,
    Invalid,

    maxCommands,
};

std::ostream &operator<<(std::ostream &out, UserCommand command);

#endif