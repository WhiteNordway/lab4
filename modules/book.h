#ifndef BOOK_H_
#define BOOK_H_


#include <iostream>
#include <string>

struct Book
{
   Book(std::string title, std::string author, std::string genre);
   virtual void displayInfo() const;
};

struct Fiction: public Book
{
   Fiction(std::string title, std::string author, std::string genre);
   void displayInfo() const override;
};

struct NonFiction: public Book
{
   NonFiction(std::string title, std::string author, std::string genre);
   void displayInfo() const override;
};


#endif