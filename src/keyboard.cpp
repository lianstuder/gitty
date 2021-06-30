#include "keyboard.h"

#include <sys/types.h>
#include <sys/timeb.h>

namespace gitty
{
    void changemode(int dir)
    {
        static struct termios, oldt, newt;

        if (dir == 1)
        {
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        }
        else
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
    int gt_kbhit()
    {
        struct timeval tv;
        fd_set rdfs;

        tv.tv_sec = 0;
        tv.tv_usec = 0;

        FD_ZERO(&rsfs);
        FD_SET(STDIN_FILENO, &rdfs);

        select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);
        return FD_ISSET(STDIN_FILENO, &rdfs)
    }
} // namespace gitty