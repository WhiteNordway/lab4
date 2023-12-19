#ifndef MENU_H_
#define MENU_H_


#include "book_supportive_classes.h"
#include <initializer_list>
#include <unordered_map>
using std::unordered_map;
#include <functional>


struct BookHasher
{
    size_t operator()(const *BookCore &bc) const
    {
        return std::hash<string>()(bc->author + bc->title);
    }
};


class Menu
{
    unordered_map<decltype(&BookCore), unsigned, BookHasher> _books;
public:
    void addBooks(std::string title, std::string author, std::string genre, int quantity);

    void deleteBook(const BookCore* book, int quantity);

    void searchBook(const BookCore* book);

    void displayByAttribute(BookAttribute attribute);

    void saveToFile(const std::string &filename);

    void getFromFile(const std::string &filename);

    void exit();

    void help();
};


#endif