#include "modules/book.h"
#include "modules/menu.h"
#include <map>
using std::cout;
using std::cerr;
using std::cin;
using std::string;
using std::map;


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


int main()
{
   Menu menu;

   cout << "Hello and welcome to the library.";
   menu.help();
   char option;
   
   const map<string, BookAttribute> _attributesMap{
      {"title", Title}, {"author", Author}, {"genre", Genre}};

   while (true)
   {
    cout << "$ Select option: ";
    cin >> option;
    switch (option)
    {
    case 'h':
        menu.help();
        break;
    case 0:
        return EXIT_SUCCESS;
    case 1:
        {
            cout << "\nEnter name of the file (without .txt): ";
            string fileName;
            menu.getFromFile(fileName);
        }
        break;
    case 2:
        {
            cout << "\nEnter name of the file (without .txt): ";
            string fileName;
            menu.saveToFile(fileName);
        }
        break;
    case 3:  // Add books
        {
            const char *delim = " %% ";
            cout << "\nEnter data in format: title %% author %% genre %% quantity" << std::endl;
            string data;
            cin >> data;
            const auto beg = data.begin();
            const auto end = data.end();

            size_t title_end = data.find(delim);
            if (title_end == string::npos)
            {
                cerr << "\n~ Invalid input format" << std::endl;
                continue;
            }
            size_t author_end = data.find(delim, title_end + 4);
            if (author_end == string::npos)
            {
                cerr << "\n~ Invalid input format" << std::endl;
                continue;
            }
            size_t genre_end = data.find(delim, title_end + 4);
            if (genre_end == string::npos)
            {
                cerr << "\n~ Invalid input format" << std::endl;
                continue;
            }
            

            string title(beg, beg + title_end);
            string author(beg + title_end, beg + author_end);
            string genre(beg + author_end, beg + genre_end);
            string quantity_string(beg + genre_end, end);

            if (title.empty() || author.empty() || genre.empty() || quantity_string.empty())
            {
                std::cout << "\n~ You must pass all the parameters" << std::endl;
                continue;
            }
                        
            int quantity;
            try
            {
                quantity = std::stoi(quantity_string);
            }
            catch(const std::exception& e)
            {
                std::cerr << "\n~ Quality must be an integer" << std::endl;
                continue;
            }
            
            menu.addBooks(title, author, genre, std::stoi(quantity_string));
        }
    case 4:  // Delete books
        {
            const char *delim = " %% ";
            cout << "\nEnter data in format: title %% author %% quantity" << std::endl;
            string data;
            cin >> data;
            const auto beg = data.begin();
            const auto end = data.end();

            size_t title_end = data.find(delim);
            if (title_end == string::npos)
            {
                cerr << "\n~ Invalid input format" << std::endl;
                continue;
            }
            size_t author_end = data.find(delim, title_end + 4);
            if (author_end == string::npos)
            {
                cerr << "\n~ Invalid input format" << std::endl;
                continue;
            }
            

            string title(beg, beg + title_end);
            string author(beg + title_end, beg + author_end);
            string quantity_string(beg + author_end, end);

            if (title.empty() || author.empty() || quantity_string.empty())
            {
                cerr << "\n~ You must pass all the parameters" << std::endl;
                continue;
            }

            int quantity;
            try
            {
                quantity = std::stoi(quantity_string);
            }
            catch(const std::exception& e)
            {
                std::cerr << "\n~ Quality must be an integer" << std::endl;
                continue;
            }
            
            menu.deleteBook(BookCore(title, author), quantity);
        }
    case 5:  // Search book
        {
            const char *delim = " %% ";
            cout << "\nEnter data in format: title %% author" << std::endl;
            string data;
            cin >> data;
            const auto beg = data.begin();
            const auto end = data.end();

            size_t title_end = data.find(delim);
            if (title_end == string::npos)
            {
                cerr << "\n~ Invalid input format" << std::endl;
                continue;
            }

            string title(beg, beg + title_end);
            string author(beg + title_end, end);

            if (title.empty() || author.empty())
                std::cerr << "\n~ You must pass all the parameters" << std::endl;
            else
                menu.searchBook(BookCore(title, author));
        }
    case 6:  // Display the library
        {
            cout << "\nEnter the attribute (title, author or genre)" << std::endl;
            string attribute;
            cin >> attribute;
            if (_attributesMap.find(attribute) == _attributesMap.end())
                std::cerr << "\n~ Invalid attribute" << std::endl;
            else
                menu.displayByAttribute(_attributesMap.at(attribute));
        }
    default:
        cout << "\nUnexisting option. Type \"h\" for help";
      }
   }
}