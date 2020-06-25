#pragma once
#include <iostream>
#include <vector>

class Book;
using std::istream;

class Library
{
private:
	std::vector<Book*> BookList;
	std::vector<Book*>::iterator it = BookList.begin();

public:

	Library();

	void init();
	void Add();
	void Lend();
	void Return();
	void Serach();
	void Purchase();

	friend istream& operator>>(istream& in, Book& book);
};
