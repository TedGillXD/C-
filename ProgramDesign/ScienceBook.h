#pragma once
#include "Book.h"
#include <iostream>

class ScienceBook : public Book
{

public:
	ScienceBook(string BookName, string BookCode, double Pirce = 0.0, int Count = 1, string Press = "", string Author = "");
	ScienceBook(Book* book);
	ScienceBook() { this->bookclass = "¿ÆÑ§Àà"; }

	virtual void Display() const override;

	virtual string GetBookClass() const override;

	virtual bool Modify() override;

	virtual int GetBookClassNumber() override;

	friend std::istream& operator>>(std::istream& in, ScienceBook* sciencebook);

	friend std::ostream& operator<<(std::ostream& out, ScienceBook sciencebook);
};