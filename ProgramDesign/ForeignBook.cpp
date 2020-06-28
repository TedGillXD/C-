#include "ForeignBook.h"
#include "Book.h"
#include <string>
#include <iomanip>


ForeignBook::ForeignBook(string BookName, string BookCode, string Language /*= "English"*/,
	double Pirce /*= 0.0*/, int Count /*= 1*/, string Press /*= ""*/, string Author /*= ""*/)
	:Book(BookName, BookCode, Pirce, Press, Author, Count)
{
	this->Language = Language;
	bookclass = "外语类";
}

ForeignBook::ForeignBook(Book* book, string Language /*= "English"*/)
	:Book(*book)
{
	this->Language = Language;
	bookclass = "外语类";
}

void ForeignBook::Display() const
{
	using namespace std;
	string book = "《" + BookName + "》";
	cout << bookclass;
	cout << std::setiosflags(std::ios::right);
	cout << std::setw(10) << book;
	cout << std::setw(12) << BookCode;
	cout << std::setprecision(2) << std::setw(5) << Price;
	cout << std::setw(10) << Author;
	cout << std::setw(14) << Press;
	cout << std::setw(4) << Count;
	cout << std::setw(10) << Language << endl;
}

string ForeignBook::GetBookClass() const
{
	return bookclass;
}

bool ForeignBook::Modify()
{
	//@TODO: Modify the elements of the book informations
	bool judge = true;
	judge = Book::Modify();
	std::cout << "语言：";
	std::cin >> Language;
	return judge;
}

int ForeignBook::GetBookClassNumber()
{
	return Foreign;
}

string ForeignBook::GetLanguage()
{
	return Language;
}

std::istream& operator>>(std::istream& in, ForeignBook* foreignbook)
{
	in >> foreignbook->BookName
		>> foreignbook->BookCode
		>> foreignbook->Price
		>> foreignbook->Author
		>> foreignbook->Press
		>> foreignbook->Count
		>> foreignbook->Language;
	return in;
}

std::ostream& operator<<(std::ostream& out, ForeignBook foreignbook)
{
	out << std::setiosflags(std::ios::right);
	out << std::setw(10) << foreignbook.BookName;
	out << std::setw(12) << foreignbook.BookCode;
	out << std::setprecision(2) << std::setw(5) << foreignbook.Price;
	out << std::setw(10) << foreignbook.Author;
	out << std::setw(14) << foreignbook.Press;
	out << std::setw(4) << foreignbook.Count;

	return out;
}
