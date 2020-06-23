#include "ForeignBook.h"
#include "Book.h"
#include <string>


ForeignBook::ForeignBook(string BookName, string BookCode, string Language /*= "English"*/,
	double Pirce /*= 0.0*/, int Count /*= 1*/, string Press /*= ""*/, string Author /*= ""*/)
	:Book(BookName, BookCode, Pirce, Press, Author, Count)
{
	this->Language = Language;
}

ForeignBook::ForeignBook(Book book, string Language /*= "English"*/)
	:Book(book)
{
	this->Language = Language;
}

void ForeignBook::Display() const
{
	using namespace std;
	Book::Display();
}

string ForeignBook::GetBookClass() const
{
	return BookClass;
}

bool ForeignBook::Modify()
{
	return true;
}

