#include "book_supportive_classes.h"
#include <string>
using std::string;


Pair::Pair(T1 v1, T2 v2): first(v1), second(v2) {}


BookCore::BookCore(string title, string author): 
	title(title), author(author) {}
