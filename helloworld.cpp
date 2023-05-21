#include <iostream>
#include "tile.h"
#include "board.h"
#include "usercommand.h"
#include "random.h"

namespace UserInput
{
    using std::cin;

    void clearExtra()
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void clearInvalid()
    {
        cin.clear();
        clearExtra();
    }

    UserCommand getCommandFromUser()
    {
        char c;
        cin >> c;
        if (!cin)
        {
            clearInvalid();
            return UserCommand::Invalid;
        }
        else
        {
            clearExtra();
            switch (c)
            {
            case 'w':
                return UserCommand::Up;
            case 'a':
                return UserCommand::Left;
            case 's':
                return UserCommand::Down;
            case 'd':
                return UserCommand::Right;
            case 'q':
                return UserCommand::Quit;
            default:
                return UserCommand::Invalid;
            }
        }
    }

    UserCommand randDirection()
    {
        return static_cast<UserCommand>(Random::get(0, 3));
    }
}

void randomizeBoard(Board &b)
{
    constexpr int NUM_SHUFFLE = 400;
    for (int i = 0; i < NUM_SHUFFLE; ++i)
    {
        b.doMove(UserInput::randDirection());
    }
}

int main()
{
    using std::cout;

    Board b{};
    randomizeBoard(b);

    while (true)
    {
        cout << b << '\n';
        if (b.isSolved())
        {
            cout << "Congratulations! The board is solved!\n";
            break;
        }
        cout << "Enter a direction:\n";
        UserCommand command = UserInput::getCommandFromUser();
        cout << "You entered: " << command << '\n';
        if (command == UserCommand::Quit)
        {
            cout << "\n\nBye!\n\n";
            break;
        }
        b.doMove(command);
    }

    return 0;
}