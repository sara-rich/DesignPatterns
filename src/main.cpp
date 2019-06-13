
#include <iostream>

#include "AdapterPattern/AdapterPattern.h"

//void TestIteratorPattern();
void TestAdapterPattern();

//--------------------------------------------------
int main()
{
	TestAdapterPattern();
	return 0;
}

#if 0

// Iteratorパターンのテスト
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

#endif

// Adapterパターンのテスト
//--------------------------------------------------
void TestAdapterPattern()
{
	std::cout << "- default -" << std::endl;
	Target target;
	target.HelloWorld();

	std::cout << "- interface -" << std::endl;
	Adaptee* pAdapteeCase1 = new AdapterCase1();
	pAdapteeCase1->GoodbyeWorld();

	std::cout << "- transfer -" << std::endl;
	Adaptee* pAdapteeCase2 = new AdapterCase2();
	pAdapteeCase2->GoodbyeWorld();
}
