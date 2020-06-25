#pragma once
#include "Book.h"


class ScienceBook : public Book
{
public:
	ScienceBook(string BookName, string BookCode, double Pirce = 0.0, int Count = 1, string Press = "", string Author = "");

	virtual void Display() const override;

	virtual string GetBookClass() const override;

};