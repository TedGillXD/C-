#include "SocialBook.h"
#include "Book.h"

SocialBook::SocialBook(string BookName, string BookCode,
	double Pirce /*= 0.0*/, int Count /*= 1*/, string Press /*= ""*/, string Author /*= ""*/)
	:Book(BookName, BookCode, Pirce, Press, Author, Count)
{
}

void SocialBook::Display() const
{
	using namespace std;
	Book::Display();
	cout << BookClass << " ";
}

string SocialBook::GetBookClass() const
{
	return BookClass;
}

