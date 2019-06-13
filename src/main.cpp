
#include <iostream>

#include "IteratorPattern/Example.h"

void TestIteratorPattern();

//--------------------------------------------------
int main()
{
	TestIteratorPattern();
	return 0;
}

//--------------------------------------------------
void TestIteratorPattern()
{
	BookShelf shelf = BookShelf();

	shelf.Reserve(10);
	shelf.AddBook(Book("Book A"));
	shelf.AddBook(Book("Book B"));
	shelf.AddBook(Book("Book C"));

	IteratorInterface<Book>* it = shelf.Iterator();
	while (it->HasNext())
	{
		Book book = it->Next();
		std::cout << "name : " << book.GetName() << std::endl;
	}
	delete it;
}
