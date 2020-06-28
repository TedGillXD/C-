#pragma once
#include "Book.h"

class SocialBook :public Book
{

public:
	SocialBook(string BookName, string BookCode, double Pirce = 0.0, int Count = 1, string Press = "", string Author = "");
	SocialBook(Book* book);
	SocialBook() { this->bookclass = "ÈËÎÄÀà"; }

	virtual void Display() const override;

	virtual string GetBookClass() const override;

	virtual bool Modify() override;

	virtual int GetBookClassNumber() override;

	friend std::istream& operator>>(std::istream& in, SocialBook* socialbook);

	friend std::ostream& operator<<(std::ostream& out, SocialBook socialbook);
};