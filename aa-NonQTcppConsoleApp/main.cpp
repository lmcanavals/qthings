#include <iostream>
#include <thread>
#include <ncurses.h>

#include "custio.h"

using namespace std;

// drawing information
struct Info {
    int     x, y;
    int     dx, dy;
    t_color fg;
    t_color bg;
};

// draw and update position and direction
void draw(Info *info)
{
    gotoxy(info->x, info->y);
    bgcolor(info->fg);
    fgcolor(info->bg);

    cout << "press a key. x = exit";
    cout.flush();

    if (info->x <= 5 || info->x >= 60)
        info->dx *= -1;
    if (info->y <= 5 || info->y >= 20)
        info->dy *= -1;

    info->x += info->dx;
    info->y += info->dy;
}

// generate random RGB colors
void randColors(Info* info)
{
    info->bg = {ui32(rand() % 256), ui32(rand() % 256), ui32(rand() % 256)};
    info->fg = {255-info->bg.r, 255-info->bg.g, 255-info->bg.b};
}

int main()
{
    srand(ui32(time(nullptr))); // random seed set to seconds since epoch
    Info info = {10, 10, 1, 1, {}, {}};
    randColors(&info);

    initscr();              // init ncurses window
    cbreak();               // doesn't wait for enter to be pressed
    noecho();               // doesn't print character pressed
    nodelay(stdscr, true);  // disable blocking on input reads
    curs_set(0);            // hides cursor

    while (1) {
        int ch = getch();
        if (ch != ERR) {
            if (ch == 'x')
                break;
            randColors(&info);
        }
        draw(&info);
        refresh();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    gotoxy(0, 0);
    reset_color();

    return 0;
}
