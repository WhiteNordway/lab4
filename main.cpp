#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <map>
using std::map;
#include <initializer_list>


/*
Управление данными в библиотеке
1 Определение общих классов
Создать класс Book с характеристиками книги, такими как название,
автор, жанр, и методами для работы с книгой.
2 Шаблоны
Реализовать шаблонный класс Pair для хранения пары характеристик
книги, например, <std::string, std::string> для названия книги и её
автора.
3 STL
Применить алгоритмы STL для управления каталогом библиотеки,
например, сортировки книг по автору.
4 ООП
Создать классы, наследующиеся от Book, представляющие разные
жанры литературы (например, Fiction, NonFiction).
Реализовать полиморфные методы для эффективной работы с разными
видами книг.
5 Меню и файлы
Разработать текстовое меню для пользователя с опциями добавления,
поиска, сортировки и вывода данных о книгах.
Сохранение результатов каждой операции в текстовый файл "output.txt"
для документирования.
6 Дополнительные задачи
Добавить функционал изменения данных о книгах (например,
изменение жанра).
Расширить сущности и функционал, например, добавив информацию о
наличии книг в библиотеке.
*/


class Book
{
public:
    const string title, author, genre;
    Book(string title, string author, string genre): title(title), author(author), genre(genre) {}
    
    virtual void displayInfo() const
    {
        cout << "//////\nTitle: \"" << title << "\"\n"
        << "Author: " << author << '\n'
        << "Genre: " << genre << endl;
    }
};


class Fiction: public Book
{
    Fiction(string title, string author, string genre): Book(title, author, genre) {}

    void displayInfo() const override
    {
        Book::displayInfo();
        cout << "Super-genre: Fiction" << endl;
    }
};


class NonFiction: public Book
{
    NonFiction(string title, string author, string genre): Book(title, author, genre) {}

    void displayInfo() const override
    {
        Book::displayInfo();
        cout << "Super-genre: Nonfiction" << endl;
    }
};


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
    };
};


int main()
{

}