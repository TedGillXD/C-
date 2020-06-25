#include "SocialBook.h"
#include "Book.h"

SocialBook::SocialBook(string BookName, string BookCode,
	double Pirce /*= 0.0*/, int Count /*= 1*/, string Press /*= ""*/, string Author /*= ""*/)
	:Book(BookName, BookCode, Pirce, Press, Author, Count)
{
}

SocialBook::SocialBook(Book* book)
	:Book(*book)
{
}

void SocialBook::Display() const
{
	using namespace std;
	cout << BookClass << " ";
	Book::Display();
}

string SocialBook::GetBookClass() const
{
	return BookClass;
}

