#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

using std::ostream;
using std::istream;

void Book::Display() const
{
	using namespace std;
	string book = "《" + BookName + "》";
	cout << bookclass;
	cout << std::setiosflags(std::ios::right);
	cout << std::setw(10) << book;
	cout << std::setw(12) << BookCode;
	cout << std::setprecision(5) << std::setw(5) << Price;
	cout << std::setw(10) << Author;
	cout << std::setw(10) << Press;
	cout << std::setw(4) << Count << endl;

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
	return bookclass;
}

bool Book::Modify()
{
	std::string temp;
	std::cout << "请重新输入数据(输入0以退出)" << std::endl;
	std::cout << "书名：";
	std::cin >> temp;
	if (temp == "0")
	{
		return false;
	}
	BookName = temp;
	std::cout << "编号：";
	std::cin >> BookCode;
	std::cout << "价格：";
	std::cin >> Price;
	std::cout << "出版社：";
	std::cin >> Press;
	std::cout << "作者：";
	std::cin >> Author;
	return true;
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

void Book::Return()
{
	Count++;
}

int Book::GetBookClassNumber()
{
	return Null;
}

ostream& operator<<(ostream& out, Book book)
{
	out << std::setiosflags(std::ios::right);
	out << std::setw(10) << book.BookName;
	out << std::setw(12) << book.BookCode;
	out << std::setprecision(2) << std::setw(5) << book.Price;
	out << std::setw(10) << book.Author;
	out << std::setw(10) << book.Press;
	out << std::setw(4) << book.Count;

	return out;
}

istream& operator>>(istream& in, Book* book)
{
	in >> book->BookName
		>> book->BookCode
		>> book->Price
		>> book->Author
		>> book->Press
		>> book->Count;
	return in;
}
