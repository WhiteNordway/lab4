#include "menu.h"
#include "book.h"
#include "book_supportive_classes.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
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
    std::cerr << "Entered quantity is bigger then book`s one (" << bookQuantity << ')' << std::endl;
    return;
  }
  if (quantity != bookQuantity)
  { 
    _books[book] -= quantity;
    return;
  }
  auto p = _books.find(book);
  delete p->first;
  delete p.first;
  _books.erase(p);
}

void Menu::searchBook(const BookCore* book)
{
  if (_books.find(book) == -1)
  {
    std::cout << "The book is not presented in the library" << std::endl;
    return;
  }
  const Book* ptr = book;
  ptr->displayInfo();
}

using items = std::pair<decltype(&BookCore), unsigned>;
bool comp1(items b1, items b2)
{
  return b1.first->title <= b2.first->title;
}

bool comp2(items b1, items b2)
{
  return b1.first->author <= b2.first->author;
}

bool comp3(items b1, items b2)
{
  return reinterpret_cast<decltype(&Book)>(b1.first)->genre <= reinterpret_cast<decltype(&Book)>(b2.first).first->genre;
}

void Menu::displayByAttribute(BookAttribute attribute)
{
  vector<> v;
  for (auto p : _books)
    v.push_back(p);
  switch (attribute)
  {
  case Title:
    std::sort(v.begin(), v.end(), comp1);
    break;
  case Author:
    std::sort(v.begin(), v.end(), comp2);
    break;
  case Genre:
    std::sort(v.begin(), v.end(), comp3);
    break;
  }
  
  for (auto p : v)
    reinterpret_cast<decltype(&Book)>(p).displayInfo();
}

void Menu::saveToFile(const string& filename)
{
  std::string total;
  for (auto p : _books)
  {
    string temp;
    auto ptr = reinterpret_cast<decltype(&Book)>(p);
    temp = ptr->title + " %% " + ptr->author + " %% " + ptr->genre;
    total += temp + '\n';
  }
  std::ofstream out(filename);
  out << total;
  out.close;
}

void Menu::getFromFile(const string& filename)
{
  exit();

  std::ifstream in(filename, data);
  string data;
  while (std::getline(in, data))
  {
  const char* delim = " %% ";
  const auto beg = data.begin();
  const auto end = data.end();

  size_t title_end = data.find(delim);
  size_t author_end = data.find(delim, title_end + 4);
  size_t genre_end = data.find(delim, title_end + 4);

  string title(beg, beg + title_end);
  string author(beg + title_end, beg + author_end);
  string genre(beg + author_end, beg + genre_end);
  string quantity_string(beg + genre_end, end);

  int quantity = std::stoi(quantity_string);
  menu.addBooks(title, author, genre, std::stoi(quantity_string));
}

void exit()
{
  for (auto a : _books)
  {
    auto p = _books.find(a.first);
    delete p->first;
    delete p.first;
    _books.erase(p);
  }
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
