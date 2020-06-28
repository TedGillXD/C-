#pragma once
#include <iostream>

#define Empty "NULL"

using std::string;
using std::istream;
using std::ostream;

enum BookClass
{
	Null = 0,
	Science = 1,
	Social = 2,
	Foreign = 3
};

class Book
{
protected:
	string BookName;
	string BookCode;
	double Price;
	string Press;	//出版社
	string Author;
	int Count;

	string bookclass;

public:
	Book(string BookName, string BookCode, double Pirce, string Press, string Author, int Count)
	{
		this->Author = Author;
		this->BookCode = BookCode;
		this->BookName = BookName;
		this->Press = Press;
		this->Price = Pirce;
		this->Count = Count;
		this->bookclass = "无分类";
	}
	Book() { this->bookclass = "无分类"; }

	virtual void Display() const;

	virtual string GetBookName() const;
	virtual string GetBookCode() const;
	virtual double GetBookPrice() const;
	virtual int GetBookCount() const;
	virtual string GetBookPress() const;
	virtual string GetBookAuthor() const;

	virtual string GetBookClass() const;
	virtual bool Add(int numbers);

	virtual void Lend();
	virtual double Buy();
	virtual void Return();
	virtual bool Modify();

	virtual int GetBookClassNumber();

	friend ostream& operator<<(ostream& out, Book book);

	friend istream& operator>>(istream& in, Book* book);

};