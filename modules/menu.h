#ifndef MENU_H_
#define MENU_H_


#include "book_supportive_classes.h"
#include <string>


struct Menu
{
    void addBook(std::string title, std::string author, std::string genre);

    void searchBook(BookAttributes attributes);

    void displayByAttribute(BookAttribute attribute);

    void saveToFile(const std::string &filename);

    void getFromFile(const std::string &filename);

    void help();
};


#endif