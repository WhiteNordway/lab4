#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;


struct Book
{
    const string title, author, genre;
    Book(string title, string author, string genre): title(title), author(author), genre(genre) {}
    
    virtual void displayInfo() const
    {
        cout << "//////\nTitle: \"" << title << "\"\n"
        << "Author: " << author << '\n'
        << "Genre: " << genre << endl;
    }
};


struct Fiction: public Book
{
    Fiction(string title, string author, string genre): Book(title, author, genre) {}

    void displayInfo() const override
    {
        Book::displayInfo();
        cout << "Super-genre: Fiction" << endl;
    }
};


struct NonFiction: public Book
{
    NonFiction(string title, string author, string genre): Book(title, author, genre) {}

    void displayInfo() const override
    {
        Book::displayInfo();
        cout << "Super-genre: Nonfiction" << endl;
    }
};
