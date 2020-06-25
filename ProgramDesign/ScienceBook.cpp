#include "ScienceBook.h"
#include "Book.h"


using ::std::string;

ScienceBook::ScienceBook(string BookName, string BookCode, 
	double Pirce /*= 0.0*/, int Count /*= 1*/, string Press /*= ""*/, string Author /*= ""*/)
	:Book(BookName, BookCode, Pirce, Press, Author, Count)
{
}

ScienceBook::ScienceBook(Book* book)
	:Book(*book)
{
}

void ScienceBook::Display() const
{
	using namespace std;
	cout << BookClass << " ";
	Book::Display();
}

string ScienceBook::GetBookClass() const
{
	return BookClass;
}
