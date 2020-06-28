#include "SocialBook.h"
#include "Book.h"
#include <iomanip>

SocialBook::SocialBook(string BookName, string BookCode,
	double Pirce /*= 0.0*/, int Count /*= 1*/, string Press /*= ""*/, string Author /*= ""*/)
	:Book(BookName, BookCode, Pirce, Press, Author, Count)
{
	bookclass = "人文类";
}

SocialBook::SocialBook(Book* book)
	:Book(*book)
{
	bookclass = "人文类";
}

void SocialBook::Display() const
{
	using namespace std;
	Book::Display();
}

string SocialBook::GetBookClass() const
{
	return bookclass;
}

bool SocialBook::Modify()
{
	//@TODO: Modify the elements of the book informations
	return false;
}

int SocialBook::GetBookClassNumber()
{
	return Social;
}

std::istream& operator>>(std::istream& in, SocialBook* socialbook)
{
	in >> socialbook->BookName
		>> socialbook->BookCode
		>> socialbook->Price
		>> socialbook->Author
		>> socialbook->Press
		>> socialbook->Count;

	return in;
}

std::ostream& operator<<(std::ostream& out, SocialBook socialbook)
{
	out << std::setiosflags(std::ios::right);
	out << 3 << " ";
	out << std::setw(20) << socialbook.BookName;
	out << std::setw(13) << socialbook.BookCode;
	out << std::setprecision(2) << std::setw(7) << socialbook.Price;
	out << std::setw(20) << socialbook.Author;
	out << std::setw(20) << socialbook.Press;
	out << std::setw(5) << socialbook.Count;

	return out;
}
