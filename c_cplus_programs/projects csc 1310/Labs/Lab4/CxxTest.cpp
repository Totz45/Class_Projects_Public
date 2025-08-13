#include "Bridges.h"
#include "DataSource.h"
#include "List.h"
#include <vector>
#include <iostream>

using namespace bridges;

int main() {
  Bridges bridges (4, "", "");
  bridges.setTitle("linked list");
  DataSource ds;

  string author = "Charlotte Bronte";  //feel free to change this to whatever author you want
  int addPos = 2, delPos = 5;  //you can change these if you want

  std::vector< GutenbergBook > books = ds.getGutenbergBookMetaData(author, "author");
  cout << "build list\n";
  //Building linked list
  List bookList(books);
  
	// provide BRIDGES a handle to the data structure
	bridges.setDataStructure(bookList.getHead());

	// visualize
	bridges.visualize();

  //we recently discovered a new book that was written by this dead author and never published!
  GutenbergBook newBook;
  newBook.setTitle("new book");
  bookList.insertNode(addPos, newBook);
  
	bridges.visualize();

  //we also found out one of their published works was misatributed. Someone else wrote it!
  bookList.deleteNode(delPos);
  
	bridges.visualize();

} 