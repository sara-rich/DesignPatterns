#pragma once

#include <string>

#include "IteratorPattern.h"

//--------------------------------------------------
class Book
{
public:

	Book() {};

	Book(std::string name) { m_name = name; }

	std::string GetName() const { return m_name; }

private:

	std::string m_name;
};

//--------------------------------------------------
class BookShelf : public AggregateInterface<Book>
{
public:

	BookShelf() : m_pBooks(nullptr), m_nowSize(0), m_maxSize(0) {};

	virtual ~BookShelf() {};

	virtual IteratorInterface<Book>* Iterator();

	void AddBook(const Book& item)
	{
		m_pBooks[m_nowSize++] = item;
	}

	const Book& GetBook(int index) const
	{
		return m_pBooks[index];
	}

	size_t GetSize() const
	{
		return m_nowSize;
	}

	void Reserve(size_t size)
	{
		if (size > m_maxSize)
		{
			m_maxSize = size;
			Book* newData = new Book[size];
			Book* oldData = m_pBooks;

			for (size_t i = 0; i < m_nowSize; i++)
			{
				newData[i] = oldData[i];
			}
			m_pBooks = newData;
			delete[] oldData;
		}
	}

private:

	Book* m_pBooks;

	size_t m_nowSize;

	size_t m_maxSize;
};

//--------------------------------------------------
class BookShelfIterator : public IteratorInterface<Book>
{
public:

	BookShelfIterator(BookShelf& shelf) : m_pShelf(&shelf), m_index(0) {};

	virtual ~BookShelfIterator() {};

	virtual const Book& Next()
	{
		return m_pShelf->GetBook(m_index++);
	};

	virtual const bool HasNext() const
	{
		return (m_index < m_pShelf->GetSize());
	};

private:

	BookShelf* m_pShelf;

	int m_index;
};

// ˆÈ‰º‚ª’è‹`ˆË‘¶‚É‚È‚é

IteratorInterface<Book>* BookShelf::Iterator()
{
	return new BookShelfIterator(*this);
}
