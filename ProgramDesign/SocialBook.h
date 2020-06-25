#pragma once
#include "Book.h"

class SocialBook :public Book
{
private:

public:
	SocialBook(string BookName, string BookCode, double Pirce = 0.0, int Count = 1, string Press = "", string Author = "");

	virtual void Display() const override;

	virtual string GetBookClass() const override;
};