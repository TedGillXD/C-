#pragma once

using ::std::string;

class Book;

class SocialBook :public Book
{
private:
	string BookClass = "SocialBook";

public:
	SocialBook(string BookName, string BookCode, double Pirce = 0.0, int Count = 1, string Press = "", string Author = "");

};