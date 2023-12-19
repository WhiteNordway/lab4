#include "book_supportive_classes.h"
#include <string>
using std::string;


template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    
    Pair() {}
    Pair(T1 v1, T2 v2): first(v1), second(v2) {}
};
using stringPair = Pair<string, string>;


struct BookCore: private stringPair
{
    const string &title;
    const string &author; 
    BookCore(string title, string author): 
        stringPair(title, author), title(first), author(second) {}
};
