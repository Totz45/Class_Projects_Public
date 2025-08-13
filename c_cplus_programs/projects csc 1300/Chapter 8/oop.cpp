#include <iostream>
#include <string>
using namespace std;

class Book
{
	private:
		int id;
		string bookName;
		string authorName;
	public:
		void setBookName(string);
		void setAuthorName(string);
		string getAuthorName();
		string getBookName();
};

void Book::setBookName(string name)
{
	bookName = name;
}
void Book::setAuthorName(string name)
{
	authorName = name;
}
string Book::getAuthorName()
{
	return authorName;
}
string Book::getBookName()
{
	return bookName;
}

int main()
{
	Book b;  //instance (object) of the Book class
	
	//b.bookName = "The Giver";
	b.setBookName("The Giver");
	
	cout << b.getBookName();
	// I will make a call to the defined member functions by using the object b
	
	return 0;
}

