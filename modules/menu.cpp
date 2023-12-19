#include "menu.h"
#include "book.h"
#include "book_supportive_classes.h"

#include <iostream>
#include <string>
using std::string;
using std::unordered_map;


void Menu::addBooks(string title, string author, string genre, int quantity)
{
  BookCore* ptr = new Book(title, author, genre);
  _books[ptr] = quantity;
}

void Menu::deleteBook(const BookCore *book, int quantity)
{
  unsigned bookQuantity = _books[book];
  if (quantity <= 0)
  {
    std::cerr << "Invalid quantity" << std::endl;
    return;
  }
  if (quantity > bookQuantity)
  {
    std::cerr << "Entered quantity is bigger then book`s one (" << bookQuantity << ')' 
  }
 
}

void Menu::searchBook(const BookCore* book)
{

}

void Menu::displayByAttribute(BookAttribute attribute)
{

}

void Menu::saveToFile(const string& filename)
{

}

void Menu::getFromFile(const string& filename)
{

}

void Menu::help()
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
