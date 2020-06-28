#include "ScienceBook.h"
#include "Book.h"
#include <iomanip>

using std::string;

ScienceBook::ScienceBook(string BookName, string BookCode, 
	double Pirce /*= 0.0*/, int Count /*= 1*/, string Press /*= ""*/, string Author /*= ""*/)
	:Book(BookName, BookCode, Pirce, Press, Author, Count)
{
	bookclass = "自然类";
}

ScienceBook::ScienceBook(Book* book)
	:Book(*book)
{
	this->bookclass = "科学类";
}

void ScienceBook::Display() const
{
	using namespace std;
	Book::Display();
}

string ScienceBook::GetBookClass() const
{
	return bookclass;
}

bool ScienceBook::Modify()
{
	//@TODO: Modify the elements of the book informations
	return false;
}

int ScienceBook::GetBookClassNumber()
{
	return Science;
}

std::istream& operator>>(std::istream& in, ScienceBook* sciencebook)
{
	in >> sciencebook->BookName
		>> sciencebook->BookCode
		>> sciencebook->Price
		>> sciencebook->Author
		>> sciencebook->Press
		>> sciencebook->Count;

	return in;
}

std::ostream& operator<<(std::ostream& out, ScienceBook sciencebook)
{
	out << std::setiosflags(std::ios::right);
	out << 3 << " ";
	out << std::setw(20) << sciencebook.BookName;
	out << std::setw(13) << sciencebook.BookCode;
	out << std::setprecision(2) << std::setw(7) << sciencebook.Price;
	out << std::setw(20) << sciencebook.Author;
	out << std::setw(20) << sciencebook.Press;
	out << std::setw(5) << sciencebook.Count;

	return out;
}