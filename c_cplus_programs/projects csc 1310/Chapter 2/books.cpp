#include "books.h"	//need this to define class functions!
#include <iostream>
#include <string>
using namespace std;

void Book::setBookName(string name)
{
	bookName = name;
}
void Book::setAuthorName(string name)
{
	authorName = name;
}
string Book::getAuthorName()const
{
	return authorName;
}
string Book::getBookName()const
{
	return bookName;
}