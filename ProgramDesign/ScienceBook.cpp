#include "ScienceBook.h"
#include "Book.h"


using ::std::string;

ScienceBook::ScienceBook(string BookName, string BookCode, 
	double Pirce /*= 0.0*/, int Count /*= 1*/, string Press /*= ""*/, string Author /*= ""*/)
	:Book(BookName, BookCode, Pirce, Press, Author, Count)
{
}

void ScienceBook::Display() const
{
	using namespace std;
	Book::Display();
	cout << BookClass << endl;
}

string ScienceBook::GetBookClass() const
{
	return BookClass;
}
