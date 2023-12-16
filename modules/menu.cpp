#include "menu.h"
#include "book.h"
#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <map>
using std::map;
#include <initializer_list>


template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    
    Pair() {}
    Pair(T1 v1, T2 v2): first(v1), second(v2) {}
};
using BookAttributes = Pair<string, string>;


struct Menu
{

    void addBook();

    void searchBook();

    void sortBooksByAuthor();

    void saveToFile(const string &filename);

    void getFromFile(const string &filename);

private:
    class Library
    {   
        map<BookAttributes, Book> _books;
        Library(std::initializer_list<Pair<BookAttributes, Book>> lst) 
        {
            for (auto &pair: lst)
            {
                const BookAttributes &ba = pair.first;
                const Book &b = pair.second;
                if (!_books.contains(ba))
            }
        }
    };
};