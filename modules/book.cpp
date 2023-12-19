#include "book.h"
using std::cout;
using std::endl;
using std::string;


// Book
Book::Book(string title, string author, string genre): 
    BookCore(title, author), genre(genre) {}
    
virtual void Book::displayInfo() const
{
        cout << "//////\nTitle: \"" << title << "\"\n"
        << "Author: " << author << '\n'
        << "Genre: " << genre << endl;
}


// Fiction
Fiction::Fiction(string title, string author, string genre):
    Book(title, author, genre) {}

void Fiction::displayInfo() const override
{
    Book::displayInfo();
    cout << "Super-genre: Fiction" << endl;
}


// NonFiction
NonFiction::NonFiction(string title, string author, string genre): 
    Book(title, author, genre) {}

void NonFiction::displayInfo() const override
{
    Book::displayInfo();
    cout << "Super-genre: Nonfiction" << endl;
}
