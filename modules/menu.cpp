#include "menu.h"
#include "book.h"
#include "book_supportive_classes.h"

#include <iostream>
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <initializer_list>


struct Menu
{

    void addBook(string title, string author, string genre);

    void searchBook(BookAttributes attributes);

    void displayByAttribute(BookAttribute attribute);

    void saveToFile(const string &filename);

    void getFromFile(const string &filename);

    void help()
    {
        std::cout << "Available commands: \n"
        << "You can type \"h\" to see this list again."
        << "\n0 — Exit"
        << "\n1 — Get data from file"
        << "\n2 — Load data to file"
        << "\n3 — Add book to the library"
        << "\n4 — Search book in the library"
        << "\n5 — Display the books sorted by attribute" << std::endl;
    }

private:

    class Library
    {   
        unordered_map<BookAttributes, Book> _books;
        Library();

    public:
        Library(std::initializer_list<Pair<BookAttributes, Book>> lst): Library() 
        {
            for (auto &pair: lst)
            {
                const BookAttributes &ba = pair.first;
                const Book &b = pair.second;
            }
        }
    };
};