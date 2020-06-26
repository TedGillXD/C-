#pragma once
#include <iostream>

#define Empty "NULL"

class ostream;

using std::string;
using std::istream;

class Book
{
protected:
	string BookName;
	string BookCode;
	double Price;
	string Press;	//³ö°æÉç
	string Author;
	int Count;

public:
	Book(string BookName, string BookCode, double Pirce, string Press, string Author, int Count)
	{
		this->Author = Author;
		this->BookCode = BookCode;
		this->BookName = BookName;
		this->Press = Press;
		this->Price = Pirce;
		this->Count = Count;
	}

	virtual void Display() const;

	virtual string GetBookName() const;
	virtual string GetBookCode() const;
	virtual double GetBookPrice() const;
	virtual int GetBookCount() const;
	virtual string GetBookPress() const;
	virtual string GetBookAuthor() const;

	virtual string GetBookClass() const;
	virtual bool Modify();
	virtual bool Add(int numbers);

	virtual void Lend();
	virtual double Buy();

	friend ostream& operator<<(ostream& out, Book& book);

};