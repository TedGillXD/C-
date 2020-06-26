#include <iostream>
#include <string>
#include "Book.h"

using std::ostream;
using std::istream;

void Book::Display() const
{
	using namespace std;
	cout << BookName << " "
		<< BookCode << " "
		<< Press << " "
		<< Author << " "
		<< Count << endl;

}

string Book::GetBookName() const
{
	return BookName;
}

string Book::GetBookCode() const
{
	return BookCode;
}

double Book::GetBookPrice() const
{
	return Price;
}

int Book::GetBookCount() const
{
	return Count;
}

string Book::GetBookPress() const
{
	if (Press == "")
	{
		return Empty;
	}
	else return Press;
}

string Book::GetBookAuthor() const
{
	if (Author == "")
	{
		return Empty;
	}
	else return Author;
}

string Book::GetBookClass() const
{
	return Empty;
}

bool Book::Modify()
{
	return false;
}

bool Book::Add(int numbers)
{
	if (numbers > 0)
	{
		Count += numbers;
		return true;
	}
	else return false;
}

void Book::Lend()
{
	Count--;
}

double Book::Buy()
{
	Count--;
	return Price;
}

ostream& operator<<(ostream& out, Book& book)
{
	out << book.GetBookName() << " "
		<< book.GetBookCode() << " "
		<< book.GetBookPrice() << " "
		<< book.GetBookAuthor() << " "
		<< book.GetBookCount() << " ";
	return out;
}
