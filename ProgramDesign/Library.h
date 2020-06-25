#pragma once
#include <iostream>
#include <vector>

class Book;
using std::istream;

class Library
{
private:
	std::vector<Book*> BookList;

public:

	Library();

	void init();
	void Add();
	void AddCount();
	void Lend();
	void Return();
	void Serach();
	void Purchase();

	void ShowBookList();
};
