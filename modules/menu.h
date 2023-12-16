#ifndef MENU_H_
#define MENU_H_


#include "book.h"
#include <iostream>
#include <string>
#include <map>


template <typename T1, typename T2>
struct Pair
{
   T1 first;
   T2 second;
    
   Pair() {}
   Pair(T1 v1, T2 v2);
};
using BookAttributes = Pair<std::string, std::string>;


struct Menu
{
    void addBook();

    void searchBook();

    void sortBooksByAuthor();

    void saveToFile(const std::string &filename);

    void getFromFile(const std::string &filename);
};


#endif