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
	cout << std::setiosflags(std::ios::left);
	cout << std::setw(20) << book;
	cout << std::setw(14) << BookCode;
	cout << "￥" << std::setprecision(5) << std::setw(6) << Price;
	cout << std::setw(15) << Author;
	cout << std::setw(18) << Press;
	cout << std::setw(11) << Count;
	cout << std::setw(10) << Language << endl;
}

string ForeignBook::GetBookClass() const
{
	return bookclass;
}

bool ForeignBook::Modify()
{
	//@TODO: Modify the elements of the book informations
	bool judge = Book::Modify();
	if (judge == false)
	{
		return false;
	}
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
	out << foreignbook.BookName << " ";
	out  << foreignbook.BookCode << " ";
	out << foreignbook.Price << " ";
	out << foreignbook.Author << " ";
	out  << foreignbook.Press << " ";
	out  << foreignbook.Count;

	return out;
}
