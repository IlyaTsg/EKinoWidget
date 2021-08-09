#ifndef EKINO_H
#define EKINO_H

#include <iostream>
#include <cstdlib>
#include <string>

#define MaxStrLen 128

typedef struct films{
    std::string title;
    std::string director_name;
    std::string genre;
    std::string realese_date;
    float rating[2];
    int kinopoisk_star;
    struct films *prev;
    struct films *next;
} film;

#endif
