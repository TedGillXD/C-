#include "Book.h"

void Book::Display() const
{
	using namespace std;
	cout << BookName << " "
		<< BookCode << " "
		<< Press << " "
		<< Author << " ";

}

void Book::DisplayAdmin() const
{
	using namespace std;
	cout << BookName << " "
		<< BookCode << " "
		<< Press << " "
		<< Author << " "
		<< Count << " ";
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

ostream& operator<<(ostream& out)
{
	// TODO: insert return statement here
	out<<BookName<<" "
		<<BookCode<<" "
		<<Price<<" "
		<<Author<<" "
		<<
	return out;
}
