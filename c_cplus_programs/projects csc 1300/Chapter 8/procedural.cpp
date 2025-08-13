#include <iostream>
#include <string>
using namespace std;

struct Book
{
	int id;
	string bookName;
	string authorName;
};

string getAuthorName(Book &b);
void changeBookName(Book &b, string name);

int main()
{
	Book b;
	
	// I will make a call to the defined functions here
	
	return 0;
}
string getAuthorName(Book &b)
{
	return b.authorName;
}

void changeBookName(Book &b, string name)
{
	b.bookName = name;
}