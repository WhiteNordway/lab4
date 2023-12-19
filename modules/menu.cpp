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
    void addBooks(string title, string author, string genre, int quantity);

    void deleteBook(BookCore attributes, int quantity);

    void searchBook(BookCore attributes);

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
        << "\n3 — Add one or several identical books to the library"
        << "\n4 — Delete one or several identical books from the library"
        << "\n5 — Search book in the library"
        << "\n6 — Display the books sorted by attribute" << std::endl;
    }

private:

    class Library
    {   
        /*
        $ Book — quantity
        $ Нужен доступ к книге по её имени и автору. ? Book не подходит как ключ, потому что для поиска придётся создавать экземпляр Book
        $ 
        $ Нужно где-то хранить имеющиеся книги. Требуется вставка, удаление и поиск. 
        $ Нужно использовать имеющуюся структуру Book.

        Решение:
        Почему бы для поиска просто не использовать экземпляр класса?

        */
        unordered_map<Book, unsigned> _books;
        Library();

    public:
        Library(std::initializer_list<Pair<BookCore, Book>> lst): Library() 
        {
            for (auto &pair: lst)
            {
                const BookCore &ba = pair.first;
                const Book &b = pair.second;
            }
        }
    };
};