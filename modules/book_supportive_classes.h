#ifndef BOOK_SUPPORTIVE_CLASSES_H
#define BOOK_SUPPORTIVE_CLASSES_H


#include <string>

template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    
    Pair();
    Pair(T1 v1, T2 v2);
};
using stringPair = Pair<std::string, std::string>;


struct BookCore: private stringPair
{
    const std::string &title;
    const std::string &author; 
    BookCore(std::string title, std::string author);
};


enum BookAttribute
{
   Title,
   Author,
   Genre
};

#endif