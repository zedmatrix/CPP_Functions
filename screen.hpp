#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <sys/ioctl.h>
#include <unistd.h>
struct ScreenSize {
    int width;
    int height;
    int centerX;
    int centerY;
};

ScreenSize screenRes() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return {w.ws_col, w.ws_row, w.ws_col / 2, w.ws_row / 2};
}

#endif //SCREEN_HPP
