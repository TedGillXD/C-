#pragma once
#include "Book.h"

class ForeignBook :public Book
{
private:
	string Language;

public:
	ForeignBook(string BookName, string BookCode, string Language = "English", double Pirce = 0.0, int Count = 1, string Press = "", string Author = "");
	ForeignBook(Book* book, string Language = "English");
	ForeignBook() { Language = "English", bookclass = "ÍâÓïÀà"; }

	virtual void Display() const override;

	virtual string GetBookClass() const override;

	virtual bool Modify() override;

	virtual int GetBookClassNumber() override;

	std::string GetLanguage();

	friend std::istream& operator>>(std::istream& in, ForeignBook* foreignbook);

	friend std::ostream& operator<<(std::ostream& out, ForeignBook foreignbook);
};