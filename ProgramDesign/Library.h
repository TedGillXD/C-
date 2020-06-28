#pragma once
#include <iostream>
#include <vector>

class Book;
using std::istream;

class Library
{
private:
	std::vector<Book*> BookList;

	std::vector<Book*> ChosenBook;

	bool printLogin() const;

	void ReadDataText(std::ifstream& ifs);

public:

	Library();

	void init();
	void Add();
	void AddCount();
	void Lend();
	void Return();
	void Search();
	void Purchase();
	void Modify();

	bool ShowBookList();
};
