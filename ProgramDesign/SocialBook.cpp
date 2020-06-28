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
	bool judge = Book::Modify();
	return judge;
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
	out << 3 << " ";
	out << socialbook.BookName << " ";
	out  << socialbook.BookCode << " ";
	out  << socialbook.Price << " ";
	out  << socialbook.Author << " ";
	out  << socialbook.Press << " ";
	out  << socialbook.Count << " ";

	return out;
}
