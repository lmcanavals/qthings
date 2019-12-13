#ifndef CUSTIO_H
#define CUSTIO_H

typedef unsigned char   byte;
typedef unsigned int    ui32;

struct t_color {
    ui32 r, g, b;
};

// support for rgb colors for foreground and background
#define fgcolor(c)    std::cout<<"\x1b[38;2;"<<c.r<<";"<<c.g<<";"<<c.b<<"m"
#define bgcolor(c)    std::cout<<"\x1b[48;2;"<<c.r<<";"<<c.g<<";"<<c.b<<"m"

// reset foreground and background colors
#define reset_color() std::cout<<"\x1b[0m"

// position cursor at x column and y row
#define gotoxy(x, y)  std::cout<<"\x1b["<<y<<";"<<x<<"f"

#endif // CUSTIO_H
