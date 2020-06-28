#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <string>
#include "Book.h"
#include "ForeignBook.h"

#define PAUSE "pause"
#define REFRESH "cls"
#define EXIT_NORMAL 0
#define EXIT_DOCUMENT_ERROR 1
#define EXIT_LOGIN_FAIL 2

int StringToInt(const std::string& str)
{
	int Num;
	Num = atoi(str.c_str());
	return Num;
}

double StringToDouble(const std::string& str)
{
	double Num;
	Num = atof(str.c_str());
	return Num;
}

int CharToNum(char& num)
{
	return atoi(&num);
}

void DocumentCheck(std::ofstream& ofs)
{
	if (!ofs.is_open())
	{
		exit(EXIT_DOCUMENT_ERROR);
	}
}

void DocumentCheck(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		exit(EXIT_DOCUMENT_ERROR);
	}
}

void OutputDataText(std::ofstream& ofs, Book book, int bookclass)
{
	DocumentCheck(ofs);
	ofs << std::endl << bookclass << " " << book;
}

void OutputDataText(std::ofstream& ofs, ForeignBook book)
{
	DocumentCheck(ofs);
	ofs << std::endl << Foreign << " " << book << " " << book.GetLanguage();
}

std::string GetRandomNumberInString()
{
	std::default_random_engine dre;
	std::uniform_int_distribution<int> di(1000000, 9999999);
	std::string Num = std::to_string(di(dre));
	return Num;
}

bool IsBooksLendOut()
{
	std::ifstream BorrowedBook("BorrowedBook.dat");
	DocumentCheck(BorrowedBook);
	char test;
	BorrowedBook >> test;
	if (BorrowedBook.eof())
	{
		return false;
	}
	else return true;
}