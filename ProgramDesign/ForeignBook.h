#pragma once
#include "Book.h"

class ForeignBook :public Book
{
private:
	string BookClass = "Foreign";
	string Language;

public:
	ForeignBook(string BookName, string BookCode, string Language = "English", double Pirce = 0.0, int Count = 1, string Press = "", string Author = "");
	ForeignBook(Book book, string Language = "English");

	virtual void Display() const override;

	virtual string GetBookClass() const override;

	virtual bool Modify() override;
};