#include "usercommand.h"

std::ostream &operator<<(std::ostream &out, UserCommand command)
{
    switch (command)
    {
    case UserCommand::Up:
        return out << "Up";
    case UserCommand::Down:
        return out << "Down";
    case UserCommand::Left:
        return out << "Left";
    case UserCommand::Right:
        return out << "Right";
    case UserCommand::Quit:
        return out << "Quit";
    default:
        return out << "Unknown Command";
    }
}