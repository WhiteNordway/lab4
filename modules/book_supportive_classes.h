#ifndef BOOK_SUPPORTIVE_CLASSES_H
#define BOOK_SUPPORTIVE_CLASSES_H


#include <string>

template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    
    Pair() {}
    Pair(T1 v1, T2 v2): first(v1), second(v2) {}
};

enum BookAttribute
{
   Title,
   Author,
   Genre
};


using BookAttributes = Pair<std::string, std::string>;


#endif